#pragma once 
#define BOOST_UUID_USE_SSE2
 //  add_compile_definitions(BOOST_UUID_USE_SSE2)
#include "../include/Event_core.hpp"


namespace CORE {
    namespace Domain {
        
        boost::uuids::uuid Event::generateUUID () {
            boost::uuids::random_generator generator_coreV;
            boost::uuids::uuid GenUUID = generator_coreV();
            return GenUUID;
        };
        
        virtual nlohmann::json Event::toJson() const {
            /*code*/
            return jt;
        }

        static std::shared_ptr<Event> Event::FromJson (const nlohmann::json& js) { 
            try {
                if (!js.contains("event_type") || !js.contains("event_uuid")) {
                    throw std::runtime_error("Event keys and arguments were not found in the file!")
                    // return nullptr;
                }    
                auto _event = std::make_shared<Event>();
                boost::uuids::string_generator str_gen;
                
                _event -> str_gen(js["event_uuid"].get<std::string>());
                std::uint8_t type_value = js["event_type"].get<std::uint8_t>();

            } catch(const std::exception& exc) {
                std::cerr << "Error: " << exc.what() << '\n';
                return nullptr;
            }
        };
        
    } /* namespace Domain */
}; /* namespace CORE */

