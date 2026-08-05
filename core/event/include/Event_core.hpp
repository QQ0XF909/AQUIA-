#pragma once 
#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
#include <memory>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>
/*uuid Boost  https://www.boost.org/doc/libs/1_73_0/libs/uuid/doc/uuid.html*/

#include <cstdio>
#include <nlohmann/json.hpp>
#include <functional>
#include <stdexcept>

namespace CORE {
    namespace Domain {
        enum class EventType : std::uint8_t {
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

                const std::string& getEventID() const noexcept { return const boost::uuds::to_string(EventUUID); }
                EventType getEventType() const noexcept { return EventTYPE; }
                std::chrono::system_clock::time_point getOccurredAt() const noexcept { return Timing; }

                virtual nlohmann::json toJson() const ;
                static std::shared_ptr<Event> FromJson(const nlohmann::json& jt);
            protected:
                Event(const Event&) =  default;
                Event(Event&&) = default;
            private:
                boost::uuids::random_genrator generateUUID ();
                EventType EventTYPE = EventType::Unknown;
                std::chrono::system_clock::time_point Timing;
                boost::uuids::uuid EventUUID; 
                /* std::string USER_LOGIN; */
        };
    }  /* namespace Domain */
} /* namespace CORE */
