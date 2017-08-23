#pragma once
#include <cstdint>

//TODO: possible to create new genders? how is gender defined? more depth here?
/*enum Sex : uint8_t {

};

struct Gender {
	
};*/

enum Gender : uint8_t {
    GENDER_MALE,
    GENDER_FEMALE,
    GENDER_TRANS_MALE,
    GENDER_TRANS_FEMALE,
    GENDER_QUEER
};