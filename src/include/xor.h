#ifndef _XOR_H
#define _XOR_H
class XOR
{
	public:
		XOR();

		void set();
		void set(bool);
		void set(bool, bool);
		bool get();

	private:
		bool input1;
		bool input2;
};
#endif
