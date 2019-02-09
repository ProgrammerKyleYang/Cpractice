 ///
 /// @file    Line.h
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-25 13:39:31
 ///
 
#ifndef __WD_LINE_H__
#define __WD_LINE_H__

class Line
{
public:
	Line(int, int, int, int);

	~Line();
	
	void printLine() const;

	class LineImpl;//前项声明

private:
	LineImpl * _pimpl;
};
#endif
