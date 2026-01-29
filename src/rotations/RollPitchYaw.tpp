#pragma once

#include <concepts>

#include "RollPitchYaw.hpp"
#include "common.hpp"

template <std::floating_point Real>
RollPitchYaw<Real>::RollPitchYaw(const Real& roll, const Real& pitch, const Real& yaw)
    : roll_(normalizeDegrees(roll)), pitch_(normalizeDegrees(pitch)), yaw_(normalizeDegrees(yaw))
{
}

template <std::floating_point Real>
auto RollPitchYaw<Real>::roll() const -> Real
{
    return roll_;
}

template <std::floating_point Real>
auto RollPitchYaw<Real>::roll(const Real& rollAngle) -> void
{
    roll_ = normalizeDegrees(rollAngle);
}

template <std::floating_point Real>
auto RollPitchYaw<Real>::pitch() const -> Real
{
    return pitch_;
}

template <std::floating_point Real>
auto RollPitchYaw<Real>::pitch(const Real& pitchAngle) -> void
{
    pitch_ = normalizeDegrees(pitchAngle);
}

template <std::floating_point Real>
auto RollPitchYaw<Real>::yaw() const -> Real
{
    return yaw_;
}

template <std::floating_point Real>
auto RollPitchYaw<Real>::yaw(const Real& yawAngle) -> void
{
    yaw_ = normalizeDegrees(yawAngle);
}
