/*
 * IDer.h
 *
 *  Created on: Dec 14, 2011
 *      Author: bovi
 */

/*
Copyright (c) 2013 by Rosalba Giugno

FocusSearchC++ is part of the RI Project.
FocusSearchC++ is a C++ implementation of the original software developed in
Modula2 and provided by the authors of:
Ullmann JR: Bit-vector algorithms for binary constraint satisfaction and
subgraph isomorphism. J. Exp. Algorithmics 2011, 15:1.6:1.1-1.6:1.64.

FocusSearchC++ is provided under the terms of The MIT License (MIT):

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


#ifndef IDER_H_
#define IDER_H_

#include "size_t.h"
#include "mp_AttributeComparator.h"

#include "debug.h"
#include <map>

class IDer{
private:

	map<std::string, int> imap;

public:
	IDer() {
	}

	~IDer(){
	}

	u_size_t idFor(void* value){
		int ret = 0;
		if(value == NULL){
			ret = 0;
		}
		else{
			map<std::string, int>::iterator IT = imap.find(*((std::string*)value));
			if(IT == imap.end()){
				imap.insert(*(new pair<std::string, int>(*((std::string*)value), ((int)imap.size())+1)));
				ret = ((int)imap.size());
			}
			else{
				ret = IT->second;
			}
		}
		return ret;
	}

};


#endif /* IDER_H_ */
