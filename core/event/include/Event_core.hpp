#pragma once 
#include <string>
#include <cstdint>
#include <chrono>
#include <memory>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>

/* Uuid от Boost  https://www.boost.org/doc/libs/1_73_0/libs/uuid/doc/uuid.html */

#include <stdio.h>
#include <nlohmann/json.hpp>
#include <functional>
#include <stdexcept>

namespace CORE::Domain {

    enum class EventType : uint8_t {
        Unknown = 0,
        UserLogin,
        UserLogout,
        UserRegistered,
        UserAgeSent,
        MessageDelivered,
        MessageRead,
        MessageDeleteOnlyForYourself,
        DeleteForEveryone,
        MessageDelete,
        PostCreated,
        PostDelete
    };
 
    class Event {
        public :
            Event () = default;

            explicit Event (EventType type) :
                EventUUID(generateUUID()), EventTYPE(type), Timing(std::chrono::system_clock::now()){
                    if (type == EventType::Unknown){ 
                        std::cout << "Warning : Event is unknown type!" << std::endl; 
                    }
            };

            virtual ~Event() = default;

           /* ================================= гетеры и сетеры ====================================*/
            const std::string& getEventID() const noexcept { return EventUUID; }
            EventType getEventType() const noexcept { return EventTYPE; }
            std::chrono::system_clock::time_point getOccurredAt() const noexcept { return Timing; }
           /* ===================================================================================== */

           
            virtual nlohmann::json toJson() const {
                nlohmann::json jt;
                jt["event_uuid"] = EventUUID;
                jt["event_type"] = static_cast<uint8_t>(EventTYPE);
                jt["event_time"] = std::chrono::duration_cast<std::chrono::milliseconds>(
                                                                Timing.time_since_epoch()).count();
                return jt;
            }
            // ============================ переписываем 
            static std::shared_ptr<Event> FromJson(const nlohmann::json& jt){
                if (!jt.contains("evennt_type") || !jt.contains("evennt_type")){
                    return nullptr;
                }
                
                auto eve = std::make_shared<Event>();
                eve->EventUUID = jt.["event_uuid"].get<std::string>();
                eve->EventTYPE = static_cast<EventType>(jt["event_type"].get<uint8_t>());
                if (jt.contains("event_time")){
                    auto ms = jt["event_time"].get<uint64_t>();
                    eve->Timing = std::chrono::system_clock::time_point(std::chrono::milliseconds(ms));                  
                }
            }
          // ============================
        protected:
            Event(const Event&) =  default;
            Event(Event&&) = default;
        private:
            boost::uuids::random_genrator generateUUID () {};
            
            EventType EventTYPE = EventType::Unknown;
            std::chrono::system_clock::time_point Timing;

            boost::uuids::uuid EventUUID; 
            /* std::string USER_LOGIN; */
            
    };
} // namespace CORE::Domain 
