#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
#include "validation_privacy.hpp"

// TODO : ДОБАВИТЬ КЕШИРОВАНИЕ А ТАК ЖЕ ЛОГГИРОВАНИЕ ДЕЙСТВИЙ . 
// добавить многопоточную проверку данных и логирование при неудачной проверка с посткодами на сервере
// для итерации по проверкам и быстрой переборки 

namespace PROFILE  {
    
    namespace CORE {

        class profile {
            private:
                std::string _login_;
                std::string _password_;

                std::string _user_id_;
                std::string _name_ ;
                std::string _second_name_;
                std::string _phone_;
                std::string _profile_icon_;
                std::string _profile_header_;
                std::string _description_;
                std::string _status_;
                std::string _quote_;

                std::chrono::system_clock::time_point _bith_date_;
                std::chrono::system_clock::time_point _created_at;
            public:
                
                profile() = default;
                virtual ~profile() = default;
            };

        profile::profile() {}
        profile::~profile() {}
    
    } // namespace CORE

} // namespace  PROFILE

/*                                      ВАЖНО!
Можно продумать хранение в формате JSON что бы не пользоваться миграциями постоянно , 
стоит уточнить как лучше хранить данные а так же латенси в обоих случаях */

/* Использовать SIMDJSON для валидации больших данных и использовать выравнивание данных  alignas(64)
Чтобы обрабатывать массивы данных в 4–16 раз быстрее, избегайте ветвлений (if/else) внутри циклов
Используйте std::vector или std::pmr::vector с выравниванием (например, через alignas(64) для AVX-512), 
чтобы избежать промахов кэша (cache misses)

*/


