#pragma once

#ifndef TRACE
#define TRACE() { \
std::cerr << __FILE__ << " line : " << __LINE__ << std::endl;\
std::cerr.flush() ;\
}
#endif