module;

#include <string>

export module borealis.util.uri;

using namespace std;

export class URI {
    string_view str;
    string_view protocol;
    string_view host;
    string_view path;
public:
    URI(string_view str) : str(str) {
        reparse();
    }

    void reparse() {
        string_view view(str);

        auto protocolEndPos = view.find_first_of("://");
        protocol = view.substr(0, protocolEndPos);
        view.remove_prefix(protocolEndPos + 3);

        auto hostEndPos = view.find_first_of("/");
        host = view.substr(0, hostEndPos);
        view.remove_prefix(hostEndPos);

        path = view;
    }

    string_view getProtocol() {
        return protocol;
    }
    
    string_view getHost() {
        return host;
    }

    string_view getPath() {
        return path;
    }
};