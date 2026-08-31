#include "Logger_config.hpp"

    enum class SinkType : uint8_t {
        File,
        Console,
        Systemlog,
        Network,
        Custom
    }

    class Sink {
    private:
        Sink () {}
        struct SinkConfig {
            private:
                Kind kind_type = {};
                LogType log_type = {};
                LogLevel lvl = {};
                SinkType sink_type = {};
            public:
                SinkConfig();
        };
    public:
        Sink(/* args */);
        ~Sink();
    };
    
