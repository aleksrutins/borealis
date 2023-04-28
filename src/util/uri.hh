#pragma once
#include <string>

namespace borealis::util {
    class URI {
        std::string_view str;
        std::string_view protocol;
        std::string_view host;
        std::string_view path;
    public:
        URI(std::string_view str) : str(str) {
            reparse();
        }

        void reparse();

        std::string_view getProtocol() {
            return protocol;
        }
        
        std::string_view getHost() {
            return host;
        }

        std::string_view getPath() {
            return path;
        }
    };
}