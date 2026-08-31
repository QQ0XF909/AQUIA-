#pragma once

#include "Logger_config.hpp"

#include <spdlog/spdlog.h>
#include <memory>
#include <memory_resource>
#include <thread>
#include <string>
#include <mutex>
#include <filesystem>

namespace Core {
   class Logger final {
      private:
         static bool running_status = {false};
         inline static std::filesystem::path dir_path;
         inline static std::atomic<bool> validate_directory{ false };
         inline static std::atomic<bool> initialized_{ false };

         inline static std::mutex _mutex_;
      public:
         Logger() = delete;
         ~Logger() = delete;

         Logger(const Logger&) = delete;
         Logger& operator=(const Logger&) = delete;
         
         static bool init(LoggerConfig cfg = {}){
            std::lock_guard lock(_mutex_);
            dir_path = log_dir;
            try {
               if (std::filesystem::is_directory(dir_path)) {
                  validate_directory = { true };
                  running_status = true;
               } else {
                  validate_directory = { false };
                  running_status = false;
               };
            } catch(const std::exception& exc) {
               std::cerr << exc.what() << '\n';
               return false;
            }

            static void ShutDown () {
               if (running_status = running_status) {
                  spdlog::shutdown();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
                  running_status = false
               } 
            }
         };
   };   
};