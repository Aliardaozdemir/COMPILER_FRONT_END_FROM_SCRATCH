#ifndef INSTANCE_H
#define INSTANCE_H

class INSTANCE{
public:
    template<typename Base, typename T>
    inline bool instanceof(const T *ptr){
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }
};


#endif
