//
//  DebugGraph.h
//  EnvTrigger
//
//  Created by Eric Kampman on 3/6/21.
/*
MIT License

Copyright (c) 2021 Eric Kampman

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#ifndef DebugGraph_h
#define DebugGraph_h

#include <iostream>

class DebugGraph {
public:
	DebugGraph(float xmin, float xmax, int charsMin = 1, int charsMax = 40, size_t skipCount = 1)
		: skipCount_(skipCount)
	{
		calcSlopeAndIntercept(xmin, xmax, charsMin, charsMax);
	}
	
	void calcSlopeAndIntercept(float xmin, float xmax, int charsMin, int charsMax)
	{
		m_ = float(charsMax - charsMin)/(xmax - xmin);
		b_ = charsMin - (m_ * xmin);
	}
	
	int calcCharsToPrint(float val) {
		int ret = (int)(m_ * val + b_);
		assert(0 <= ret);
		return ret;
	}
	
	void print(float val) {
		if (0 == count_ % skipCount_) {
			int chars2Print = calcCharsToPrint(val);
			for (int i = 0; i < chars2Print; ++i) {
				std::cout << '.';
			}
			std::cout << std::endl;
		}
		++count_;
	}
	
	void print(float *vals, size_t count) {
		for (float *p = vals, *opl = p + count; p < opl; ++p) {
			print(*p);
		}
	}
	
private:
	float m_, b_;
	size_t skipCount_;
	size_t count_;
};
#endif /* DebugGraph_h */
