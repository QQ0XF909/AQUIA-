#pragma once 
#define BOOST_UUID_USE_SSE2
 // включить позже в сборке : add_compile_definitions(BOOST_UUID_USE_SSE2)
#include "../include/Event_core.hpp"


namespace CORE {
    namespace Domain {
        
        boost::uuids::uuid Event::generateUUID () {
            boost::uuids::random_generator generator_coreV;
            boost::uuids::uuid GenUUID = generator_coreV();
            return GenUUID;
        };
        
        virtual nlohmann::json Event::toJson() const {



            return jt;
        }

        static std::shared_ptr<Event> Event::FromJson (const nlohmann::json& js) { 
            if (!js.contains("event_type")) {
                return nullptr;
            }
            auto _event = std::make_shared<Event>();
            _event -> EventUUID = boost::uuids::string_generator generator (){
                
            }

        };
        
    } /* namespace Domain */
}; /* namespace CORE */

