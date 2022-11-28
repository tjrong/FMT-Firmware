/****************************************************************************
 *
 *   Copyright (c) 2013-2022 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file MulticopterLandDetector.h
 * Land detection implementation for multicopters.
 *
 * @author Johan Jansen <jnsn.johan@gmail.com>
 * @author Morten Lysgaard <morten@lysgaard.no>
 * @author Julian Oes <julian@oes.ch>
 */

#pragma once

#include <uORB/topics/actuator_controls.h>
#include <uORB/topics/hover_thrust_estimate.h>
#include <uORB/topics/trajectory_setpoint.h>
#include <uORB/topics/vehicle_control_mode.h>
#include <uORB/topics/takeoff_status.h>

#include "LandDetector.h"

#ifdef __cplusplus
struct __EXPORT actuator_controls_s {
#else
struct actuator_controls_s {
#endif

	uint64_t timeStampUs;
	float throttle;
	bool updated;

#ifdef __cplusplus
#endif
};

#ifdef __cplusplus
struct __EXPORT vehicle_control_mode_s {
#else
struct vehicle_control_mode_s {
#endif

	uint64_t timeStampUs;
	bool flag_multicopter_position_control_enabled;
	bool updated;

#ifdef __cplusplus

#endif
};

#ifdef __cplusplus
struct __EXPORT hover_thrust_estimate_s {
#else
struct hover_thrust_estimate_s {
#endif

	uint64_t timeStampUs;
	float hover_thrust;
	bool updated;

#ifdef __cplusplus
#endif
};

#ifdef __cplusplus
struct __EXPORT takeoff_status_s {
#else
struct takeoff_status_s {
#endif

	uint64_t timeStampUs;
	uint8_t takeoff_state;
	bool updated;

#ifdef __cplusplus
#endif
};

#ifdef __cplusplus
struct __EXPORT trajectory_setpoint_s {
#else
struct trajectory_setpoint_s {
#endif

	uint64_t timeStampUs;
	float velocity_z;
	bool updated;

#ifdef __cplusplus
#endif
};

using namespace time_literals;

namespace land_detector
{

class MulticopterLandDetector : public LandDetector
{
public:
	MulticopterLandDetector();
	~MulticopterLandDetector() override = default;

	void set_actuator_controls_throttle(float throttle, uint64_t timeStampUs, updated){
		_actuator_controls.throttle 	= throttle;
		_actuator_controls.timeStampUs 	= timeStampUs;
		_actuator_controls.updated 		= updated;
	};
	void set_flag_control_climb_rate_enabled(bool flag_multicopter_position_control_enabled, uint64_t timeStampUs, bool updated){
		_vehicle_control_mode.flag_multicopter_position_control_enabled = flag_multicopter_position_control_enabled;
		_vehicle_control_mode.timeStampUs 								= timeStampUs;
		_vehicle_control_mode.updated 									= updated;
	};
	void set_hover_thrust_estimate_last_valid(float hover_thrust, uint64_t timeStampUs, bool updated){
		_hte.hover_thrust 	= hover_thrust;
		_hte.timeStampUs 	= timeStampUs;
		_hte.updated 		= updated;
	};
	void set_takeoff_state(uint8_t takeoff_state, uint64_t timeStampUs, bool updated){
		_takeoff_status.takeoff_state 	= takeoff_state;
		_takeoff_status.timeStampUs 	= timeStampUs;
		_takeoff_status.updated 		= updated;
	};
	void set_trajectory_setpoint(float velocity_z, uint64_t timeStampUs, bool updated){
		_trajectory_setpoint.velocity_z 	= velocity_z;
		_trajectory_setpoint.timeStampUs 	= timeStampUs;
		_trajectory_setpoint.updated 		= updated;
	};
	void set_mc_params(	float _param_lndmc_minThrottle,
						float _param_lndmc_hoverThrottle,
						float _param_lndmc_minManThrottle,
						bool  _param_lndmc_useHoverThrustEstimate,
						float _param_lndmc_landSpeed,
						float _param_lndmc_crawlSpeed,
						float _param_lndmc_trig_time,
						float _param_lndmc_rot_max,
						float _param_lndmc_xy_vel_max,
						float _param_lndmc_z_vel_max,
						float _param_lndmc_alt_gnd_effect){
		_mc_params._param_lndmc_minThrottle 			= _param_lndmc_minThrottle;
		_mc_params._param_lndmc_hoverThrottle 			= _param_lndmc_hoverThrottle;
		_mc_params._param_lndmc_minManThrottle 			= _param_lndmc_minManThrottle;
		_mc_params._param_lndmc_useHoverThrustEstimate 	= _param_lndmc_useHoverThrustEstimate;
		_mc_params._param_lndmc_landSpeed 				= _param_lndmc_landSpeed;
		_mc_params._param_lndmc_crawlSpeed 				= _param_lndmc_crawlSpeed;
		_mc_params._param_lndmc_trig_time 				= _param_lndmc_trig_time;
		_mc_params._param_lndmc_rot_max 				= _param_lndmc_rot_max;
		_mc_params._param_lndmc_xy_vel_max 				= _param_lndmc_xy_vel_max;
		_mc_params._param_lndmc_z_vel_max 				= _param_lndmc_z_vel_max;
		_mc_params._param_lndmc_alt_gnd_effect 			= _param_lndmc_alt_gnd_effect;
	};

protected:
	void _update_params() override;
	void _update_topics() override;

	bool _get_landed_state() override;
	bool _get_ground_contact_state() override;
	bool _get_maybe_landed_state() override;
	bool _get_freefall_state() override;
	bool _get_ground_effect_state() override;
	bool _get_in_descend() override { return _in_descend; }
	bool _get_has_low_throttle() override { return _has_low_throttle; }
	bool _get_horizontal_movement() override { return _horizontal_movement; }
	bool _get_vertical_movement() override { return _vertical_movement; }
	bool _get_rotational_movement() override { return _rotational_movement; }
	bool _get_close_to_ground_or_skipped_check() override { return _close_to_ground_or_skipped_check; }

	void _set_hysteresis_factor(const int factor) override;

	actuator_controls_s 	_actuator_controls;
	vehicle_control_mode_s 	_vehicle_control_mode;
	hover_thrust_estimate_s _hte;
	takeoff_status_s 		_takeoff_status;
	trajectory_setpoint_s	_trajectory_setpoint;

private:
	bool _is_close_to_ground();

	/** Time in us that freefall has to hold before triggering freefall */
	static constexpr uint64_t FREEFALL_TRIGGER_TIME_US = 300_ms;

	/** Distance above ground below which entering ground contact state is possible when distance to ground is available. */
	static constexpr float DIST_FROM_GROUND_THRESHOLD = 1.0f;

	struct {
		param_t minThrottle;
		param_t hoverThrottle;
		param_t minManThrottle;
		param_t useHoverThrustEstimate;
		param_t landSpeed;
		param_t crawlSpeed;
	} _paramHandle{};

	struct {
		float _param_lndmc_minThrottle;
		float _param_lndmc_hoverThrottle;
		float _param_lndmc_minManThrottle;
		bool  _param_lndmc_useHoverThrustEstimate;
		float _param_lndmc_landSpeed;
		float _param_lndmc_crawlSpeed;
		float _param_lndmc_trig_time,
		float _param_lndmc_rot_max,
		float _param_lndmc_xy_vel_max,
		float _param_lndmc_z_vel_max,
		float _param_lndmc_alt_gnd_effect
	} _mc_params{};

	uORB::Subscription _actuator_controls_sub{ORB_ID(actuator_controls_0)};
	uORB::Subscription _hover_thrust_estimate_sub{ORB_ID(hover_thrust_estimate)};
	uORB::Subscription _trajectory_setpoint_sub{ORB_ID(trajectory_setpoint)};

	uORB::Subscription _vehicle_control_mode_sub{ORB_ID(vehicle_control_mode)};
	uORB::Subscription _takeoff_status_sub{ORB_ID(takeoff_status)};

	uint64_t _hover_thrust_estimate_last_valid{0};
	bool _hover_thrust_estimate_valid{false};

	bool _flag_control_climb_rate_enabled{false};
	bool _hover_thrust_initialized{false};

	float _actuator_controls_throttle{0.f};

	uint8_t _takeoff_state{takeoff_status_s::TAKEOFF_STATE_DISARMED};

	systemlib::Hysteresis _minimum_thrust_8s_hysteresis{false};

	bool _in_descend{false};		///< vehicle is commanded to desend
	bool _horizontal_movement{false};	///< vehicle is moving horizontally
	bool _vertical_movement{false};
	bool _rotational_movement{false};
	bool _has_low_throttle{false};
	bool _close_to_ground_or_skipped_check{false};
	bool _below_gnd_effect_hgt{false};	///< vehicle height above ground is below height where ground effect occurs

	DEFINE_PARAMETERS_CUSTOM_PARENT(
		LandDetector,
		(ParamFloat<px4::params::LNDMC_TRIG_TIME>)   _param_lndmc_trig_time,
		(ParamFloat<px4::params::LNDMC_ROT_MAX>)    _param_lndmc_rot_max,
		(ParamFloat<px4::params::LNDMC_XY_VEL_MAX>) _param_lndmc_xy_vel_max,
		(ParamFloat<px4::params::LNDMC_Z_VEL_MAX>)  _param_lndmc_z_vel_max,
		(ParamFloat<px4::params::LNDMC_ALT_GND>)    _param_lndmc_alt_gnd_effect
	);
};

} // namespace land_detector
