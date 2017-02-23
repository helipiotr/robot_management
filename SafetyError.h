#ifndef SAFETY_ERROR_H
#define SAFETY_ERROR_H

#include <stdexcept>

using namespace std;

//!  Safety Error Exception
/*!
 * Exception thrown when safety mode does not allow requested operation
  */

class SafetyError: public runtime_error{
	public:
		SafetyError(const std::string& what) noexcept:
		runtime_error(what){};
};

#endif /* SAFETY_ERROR_H */
