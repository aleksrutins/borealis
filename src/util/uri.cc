#include "uri.hh"

using namespace std;
using namespace borealis::util;

void URI::reparse() {
    string_view view(str);

    auto protocolEndPos = view.find_first_of("://");
    protocol = view.substr(0, protocolEndPos);
    view.remove_prefix(protocolEndPos + 3);

    auto hostEndPos = view.find_first_of("/");
    host = view.substr(0, hostEndPos);
    view.remove_prefix(hostEndPos);

    path = view;
}