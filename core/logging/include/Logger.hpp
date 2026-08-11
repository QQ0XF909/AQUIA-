#pragma once
#include "Logger_config.hpp"
#include <spdlog/spdlog.h>
#include <memory>
#include <memory_resourse>
#include <thread>
#include <string>
#include <mutex>
#include <filesystem>

namespace Core {
   class Logger {
      private:
         static bool initialized_;
         std::filesystem dir_path = " ";
      public:
         Logger() { init(); };
         ~Logger();
         static void init(bool ConsoleOutput = true,  bool FileOutput = true){
            this-> dir_path = log_dir;
            if (std::filesystem::create_directory(dir_path)) {
               // логирование
            } else {
               
            }
         };
   };   
};