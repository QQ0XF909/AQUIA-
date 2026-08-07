#pragma once
#include <spdlog/spdlog.h>

namespace Core {
   class Logger {
      private:
         static bool initialized_;
      public:
         Logger() { init(); };
         ~Logger();
         static void init(bool ConsoleOutput = true,  bool FileOutput = true){};
   };   
};