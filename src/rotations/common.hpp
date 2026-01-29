#pragma once

#include <concepts>

/**
 * @brief Normalize an angle in degrees to the range (-180, 180].
 *
 * @param angle Angle (degrees).
 *
 * @return Normalized angle (degrees).
 */
template <std::floating_point Real>
auto normalizeDegrees(const Real& angle) -> Real;

/**
 * @brief Normalize an angle in radians to the range (-180, 180].
 *
 * @param angle Angle (radians).
 *
 * @return Normalized angle (radians).
 */
template <std::floating_point Real>
auto normalizeRadians(const Real& angle) -> Real;

/**
 * @brief Convert degrees to radians.
 *
 * @param degrees Angle (degrees).
 *
 * @return Converted angle (radians).
 */
template <std::floating_point Real>
auto degreesToRadians(const Real& degrees) -> Real;

/**
 * @brief Convert radians to degrees.
 *
 * @param radians Angle (radians).
 *
 * @return Converted angle (degrees).
 */
template <std::floating_point Real>
auto radiansToDegrees(const Real& radians) -> Real;

#include "common.tpp"
