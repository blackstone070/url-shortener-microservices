#include "crow_all.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// The 62 characters used for encoding
const std::string CHARSET = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Core logic: Converts a number to a Base62 string
string toBase62(long long id) {
    if (id == 0) return "0";
    string code = "";
    while (id > 0) {
        code += CHARSET[id % 62];
        id = id / 62;
    }
    reverse(code.begin(), code.end());
    return code;
}

int main() {
    crow::SimpleApp app;

    // Route: http://127.0.0.1
    CROW_ROUTE(app, "/encode/<int>")
    ([](int id) {
        // We cast the int to long long for our function
        return toBase62((long long)id);
    });

    // Start the server on port 18080
     app.port(18080).run(); 
}
