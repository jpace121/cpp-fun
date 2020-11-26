#include <iostream>

template<typename ObjectType, typename DeleterType>
class ScopeGuard
{
public:
    ScopeGuard(const ObjectType& object, const DeleterType& deleter);
    ~ScopeGuard();
    ScopeGuard(ScopeGuard&& other);
    ScopeGuard& operator=(ScopeGuard&& other);

    ObjectType get() const;

private:
    bool _valid;
    ObjectType _object;
    DeleterType _deleter;

    ScopeGuard(const ScopeGuard&) = delete;
    ScopeGuard& operator=(const ScopeGuard&) = delete;

};

template<typename ObjectType, typename DeleterType>
ScopeGuard<ObjectType, DeleterType>::ScopeGuard(const ObjectType& object, const DeleterType& deleter):
    _valid{true},
    _object{object},
    _deleter{deleter}
{
}

template<typename ObjectType, typename DeleterType>
ScopeGuard<ObjectType, DeleterType>::~ScopeGuard()
{
    if(_valid)
    {
        _deleter(_object);
        _valid = false;
    }
}

template<typename ObjectType, typename DeleterType>
ScopeGuard<ObjectType, DeleterType>::ScopeGuard(ScopeGuard&& other):
    _valid{true},
    _object{std::move(other._object)},
    _deleter{std::move(other._deleter)}
{
    other._valid = false;
}

template<typename ObjectType, typename DeleterType>
ScopeGuard<ObjectType, DeleterType>& ScopeGuard<ObjectType, DeleterType>::operator=(ScopeGuard&& other)
{
    return std::move(other);
}

template<typename ObjectType, typename DeleterType>
ObjectType ScopeGuard<ObjectType, DeleterType>::get() const
{
    if(_valid)
    {
        return _object;
    }
    else
    {
        // TODO: Throw a better type here.
        throw "This should be an option.";
    }
}

int main(int argc, char *argv[])
{
    const auto deleter = [](int a){std::cout << "Deleting " << a << std::endl;};

    {
        ScopeGuard<int, decltype(deleter)> guard{1, deleter};
    }

    {
        const auto guard = ScopeGuard<int, decltype(deleter)>{2, deleter};
    }

    {
        ScopeGuard<int, decltype(deleter)> guard{3, deleter};

        const auto ex = std::move(guard);
        std::cout << ex.get();
        std::cout << guard.get();
    }
    return 0;
}



