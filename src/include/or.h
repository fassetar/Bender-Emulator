#ifndef _OR_H
#define _OR_H
class OR
{
	public:
		OR();

		void set();
		void set(bool);
		void set(bool, bool);
		bool get();

	private:
		bool input1;
		bool input2;
};
#endif
