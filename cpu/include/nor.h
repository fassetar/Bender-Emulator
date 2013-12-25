#ifndef _NOR_H
#define _NOR_H

class NOR
{
	public:
		NOR();
		void reset();
		void seta(bool);
		void setb(bool);
		void set(bool, bool);
		bool get();

	private:
		bool a;
		bool b;
};
#endif
