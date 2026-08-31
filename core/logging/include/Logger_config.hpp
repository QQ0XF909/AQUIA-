#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <optional>

#define MB(x)((x) * 1024ULL * 1024ULL)

namespace Core {
    
    enum class LogLevel : uint8_t {
        Trace, Debug, Info, Warn, Error, Fatal
    };
    
    enum class LogCategory : uint8_t {
        Core,
        Network,
        Business, 
        Audit
    };

    struct LoggerConfig {

        bool async = {true};
        bool console{true};
        bool file{true};
        bool enable_overflow {true};

        std::size_t thread_count {2};
        
        std::string formatting_date_time = "[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%t] %v";
        std::filesystem::path log_dir = {"logs"};
        std::size_t max_file_bytes = MB(50);
        std::size_t max_files {9};
        
        
    }
    
};