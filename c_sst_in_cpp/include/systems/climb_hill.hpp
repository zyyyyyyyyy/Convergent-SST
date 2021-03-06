/**
 * @file climb_hill.hpp
 * 
 * 
 */

#ifndef SPARSE_CLIMB_HILL_HPP
#define SPARSE_CLIMB_HILL_HPP

#include "systems/system.hpp"

class climb_hill_t : public system_t
{
public:
	climb_hill_t()
	{
		state_dimension = 3;
		control_dimension = 2;
		temp_state = new double[state_dimension];
		number_of_particles = 0;
		temp_particles.clear();
	}

	climb_hill_t(unsigned in_number_of_particles)
	{
		state_dimension = 3;
		control_dimension = 2;
		temp_state = new double[state_dimension];
		number_of_particles = in_number_of_particles;
		temp_particles.clear();
		for (int i = 0; i < number_of_particles; ++i)
		{
			temp_particles.push_back(new double[state_dimension]); //+1 to store the height
		}
	}

	virtual ~climb_hill_t(){}

	virtual double distance(double* point1, double* point2);

	virtual void random_particles(double* destination, double* state, double radius);

	virtual void random_state(double* state);

	virtual void random_control(double* control);

	virtual bool propagate(double* start_state, double* control, int min_step, int max_step, double* result_state, double& duration );

	virtual bool convergent_propagate( const bool &random_time, double* start_state,std::vector<double*> &start_particles, double* control, int min_step, int max_step, double* result_state, std::vector<double*> &result_particles, double& duration, double& cost );
	
	virtual void enforce_bounds(double* state);
	
	virtual bool valid_state();

	double hill_height(double* point);
	
	double hill_gradient_x(double* point);

	double hill_gradient_y(double* point);

	virtual double cost_function(double* state, std::vector<double*> particles);

	svg::Point visualize_point(double* state, svg::Dimensions dims);

	std::string export_point(double* state);

	virtual void load_openrave() {
		return;
	};
};


#endif