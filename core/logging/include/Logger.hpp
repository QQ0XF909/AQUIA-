#pragma once
#include <spdlog/spdlog.h>

namespace Core {
   class Logger {
   private:
    static bool initialized_;
   public:
    Logger();
    ~Logger();
    staic void init(bool ConsoleOutput = true,  bool FileOutput = true){



        
    }
   };
   

   
}