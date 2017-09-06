#include "Access.h"

Access::Access(Privilege priv, AccessAction action) {
    this->priv = priv;
    this->action = action;
}

Access::~Access() {

}