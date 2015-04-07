#ifndef _AND_H
#define _AND_H
class AND
{
	public:
		AND();

		void reset();
		void set(bool);
		void set(bool, bool);
		bool get();

	private:
		bool input1;
		bool input2;
};
#endif
