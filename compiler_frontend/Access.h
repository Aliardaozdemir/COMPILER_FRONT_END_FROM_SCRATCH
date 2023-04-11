#ifndef ACCESS_H
#define ACCESS_H

#include "Op.h"
#include "Id.h"

class Access : public Op{
public:
    Access(Id *a, Expr *i, Type *p);
    Expr* gen();
    void jumping(int t, int f);
    std::string toString() const;
    ~Access();
    
    Id *array;
    Expr *index;
private:
    Word *temp1;
    Access *temp2;
};

#endif
