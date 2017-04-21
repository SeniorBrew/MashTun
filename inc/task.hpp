#ifndef TASK_HPP
#define TASK_HPP

#include <vector>

using namespace std;

class TaskList;

class Task {
	public:
        static TaskList list;

		Task(int);
		int tick(int);
		int get_period_s() {return period_ms / 1000;};
		int get_period_ms() {return period_ms;};
		int get_period_us() {return period_ms * 1000;};

	protected:
		int state;
		int period_ms;
		int elapsed_time;

    private:
		virtual int tick_function() = 0;
};

class TaskList {
	public:
		vector<Task> addTask(Task &);
		int get_period_s(void) { return period_ms / 1000; };
		int get_period_ms(void) { return period_ms; };
		int get_period_us(void) { return period_ms * 1000; };

		int init();
		static void tick(int i = 0);

	private:
		static vector<Task> tasks;
		static int period_ms;

		void set_period_s(int s) { period_ms = s * 1000; };
		void set_period_ms(int ms) { period_ms = ms; };
		void set_period_us(int us) { period_ms = us * 1000; };
        void set_timer_s(long int);
        void set_timer_ms(long int);
        void set_timer_us(long int);
		int findGCD(int);
};
#endif
