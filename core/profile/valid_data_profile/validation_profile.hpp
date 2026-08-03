#pragma once
#ifndef _VALIDATION_PROFILE_
#define _VALIDATION_PROFILE_
#include <chrono>
#include <optional>
#include <cctype>
#include <string>
#include <vector>
#include <immintrin.h> 

namespace PROFILE {
    
    namespace VALID {
     
        using Buffer = std::pmr::vector<uint8_t>;
        
        class RequestContext{
        private:
            /* data */
        public:
            RequestContext(/* args */);
            ~RequestCoxt();
        };
        
    
        



    }; // namespace VALID

}; // namespace PROFILE

#endif /* _VALIDATION_PROFILE_ */