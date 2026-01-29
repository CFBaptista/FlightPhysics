#pragma once

#include <cmath>
#include <concepts>
#include <numbers>

template <std::floating_point Real>
auto normalizeDegrees(const Real& angle) -> Real
{
    // Wrap angle to (-360, 360]
    Real normalizedAngle = std::fmod(angle, static_cast<Real>(360.0));

    // Wrap angle to (-180, 180]
    if (normalizedAngle > static_cast<Real>(180.0))
    {
        normalizedAngle -= static_cast<Real>(360.0);
    }
    if (normalizedAngle <= static_cast<Real>(-180.0))
    {
        normalizedAngle += static_cast<Real>(360.0);
    }

    return normalizedAngle;
}

template <std::floating_point Real>
auto normalizeRadians(const Real& angle) -> Real
{
    // Wrap angle to (-2*pi, 2*pi]
    Real normalizedAngle = std::fmod(angle, static_cast<Real>(2 * std::numbers::pi));

    // Wrap angle to (-pi, pi]
    if (normalizedAngle > static_cast<Real>(std::numbers::pi))
    {
        normalizedAngle -= static_cast<Real>(2 * std::numbers::pi);
    }
    if (normalizedAngle <= static_cast<Real>(-std::numbers::pi))
    {
        normalizedAngle += static_cast<Real>(2 * std::numbers::pi);
    }

    return normalizedAngle;
}

template <std::floating_point Real>
auto degreesToRadians(const Real& degrees) -> Real
{
    const Real radians{degrees * std::numbers::pi / static_cast<Real>(180.0)};
    const Real normalizedRadians{normalizeRadians(radians)};

    return normalizedRadians;
}

template <std::floating_point Real>
auto radiansToDegrees(const Real& radians) -> Real
{
    const Real degrees{radians * static_cast<Real>(180.0) / std::numbers::pi};
    const Real normalizedDegrees{normalizeDegrees(degrees)};

    return normalizedDegrees;
}
