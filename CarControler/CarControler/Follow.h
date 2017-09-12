#ifndef FOLLOW_H
#define FOLLOW_H

class Follow{
	private:
		int sensorLinhaEsq = A4;
		int sensorLinhaDir = A5;
	public:
		Follow(int sensorLinhaEsq, int sensorLinhaDir);
};

#endif
