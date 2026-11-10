#include "sbl/types.hpp"

namespace sbl {

const char* status_name(Status status) {
    switch (status) {
    case Status::Ok:
        return "ok";
    case Status::NotImplemented:
        return "not_implemented";
    case Status::InvalidInput:
        return "invalid_input";
    case Status::NoSolution:
        return "no_solution";
    }
    return "unknown";
}

}  // namespace sbl
