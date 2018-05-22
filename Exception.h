/*
 * Exceptions.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

class Exception{
private:
    string errorText;
public:
    Exception(string);

    string what();
};

Exception::Exception(string err){
    errorText = err;
}

string Exception::what(){
    return errorText;
}

#endif /* EXCEPTIONS_H_ */
