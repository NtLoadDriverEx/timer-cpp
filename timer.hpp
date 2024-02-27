#pragma once
#include <chrono>

class event_timer
{
public:
	event_timer() 
	{
		time_created = std::chrono::duration_cast<std::chrono::nanoseconds>
			(std::chrono::high_resolution_clock::now().time_since_epoch());
	};
	template<class duration>
	bool has_elapsed(duration time) 
	{
		return this->elapsed<std::chrono::nanoseconds>().count() >= std::chrono::duration_cast<std::chrono::nanoseconds>(time).count();
	}

	template<class duration>
	duration elapsed() 
	{
		const std::chrono::nanoseconds current_time = std::chrono::duration_cast<std::chrono::nanoseconds>
			(std::chrono::high_resolution_clock::now().time_since_epoch());
		
		return std::chrono::duration_cast<duration>(current_time - time_created);
	}

	void reset() {
		time_created = std::chrono::duration_cast<std::chrono::nanoseconds>
			(std::chrono::high_resolution_clock::now().time_since_epoch());
	}

private:
	std::chrono::nanoseconds time_created;
};

// comment if you do not want to profilerate the literals.
// usage static event_timer timer;
// timer.has_elapsed(1m);
using namespace std::chrono_literals;
