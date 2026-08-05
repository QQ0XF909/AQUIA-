#define BOOST_UUID_USE_SSE2 //  add_compile_definitions(BOOST_UUID_USE_SSE2)
#include "../include/Event_core.hpp"


namespace CORE {
    namespace Domain {
        
        boost::uuids::uuid Event::generateUUID () {
            boost::uuids::random_generator generator_coreV;
            boost::uuids::uuid GenUUID = generator_coreV();
            return GenUUID;
        };
        
        nlohmann::json Event::toJson() const {
            nlohmann::json js;
            js["event_uuid"] = boost::uuids::to_string(EventUUID);
            js["event_type"] = static_cast<uint8_t>(EventTYPE);
            js["event_time"] = std::chrono::duration_cast<std::chrono::milliseconds>(Timing.time_since_epoch()).count();
            return js;
        }

        std::shared_ptr<Event> Event::FromJson (const nlohmann::json& js) { 
            try {
                if (!js.contains("event_type") || !js.contains("event_uuid") || !js.contains("event_time")) {
                    throw std::runtime_error("Event keys and arguments were not found in the file!");
                }    
                
                auto _event = std::make_shared<Event>();
                boost::uuids::string_generator str_gen;

                _event -> EventUUID = str_gen(js["event_uuid"].get<std::string>());
                std::uint8_t type_value = js["event_type"].get<std::uint8_t>(); 
                
                if (type_value > static_cast<std::uint8_t>(EventType::PostDelete) || type_value == static_cast<std::uint8_t>(EventType::Unknown)) {
                    throw std::runtime_error ("Invalid event type!");
                }
                _event -> EventTYPE = static_cast<EventType>(type_value);
                auto ms = js["event_time"].get<std::uint64_t>();
                _event -> Timing = std::chrono::system_clock::time_point(std::chrono::milliseconds(ms));

                return _event;

            } catch(const std::exception& exc) {
                std::cerr << "Error: " << exc.what() << '\n';
                return nullptr;
            }
        };
        
    } /* namespace Domain */
}; /* namespace CORE */

