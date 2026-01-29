#pragma once

#include <concepts>

/**
 * @brief Represents the three Euler angles: pitch, roll and yaw.
 *
 * @details This class stores and manages the three attitude angles pitch, roll and yaw. The angles
 * are stored in degrees and normalized to the range (-180, 180].
 *
 * @tparam Real A floating-point type used to store and return angles.
 */
template <std::floating_point Real>
class RollPitchYaw
{
public:
    RollPitchYaw() = delete;

    /**
     * @brief Constructs a `RollPitchYaw` from three angles normalized to the range (-180, 180].
     *
     * @param roll Roll angle (degrees).
     * @param pitch Pitch angle (degrees).
     * @param yaw Yaw angle (degrees).
     */
    RollPitchYaw(const Real& roll, const Real& pitch, const Real& yaw);

    /**
     * @brief Returns the stored roll angle.
     *
     * @return Roll angle (degrees).
     */
    auto roll() const -> Real;

    /**
     * @brief Normalizes and sets the roll angle.
     *
     * @param rollAngle Roll angle (degrees).
     */
    auto roll(const Real& rollAngle) -> void;

    /**
     * @brief Returns the stored pitch angle.
     *
     * @return Pitch angle (degrees).
     */
    auto pitch() const -> Real;

    /**
     * @brief Normalizes and sets the pitch angle.
     *
     * @param pitchAngle Pitch angle (degrees).
     */
    auto pitch(const Real& pitchAngle) -> void;

    /**
     * @brief Returns the stored yaw angle.
     *
     * @return Yaw angle (degrees).
     */
    auto yaw() const -> Real;

    /**
     * @brief Normalizes and sets the yaw angle.
     *
     * @param yawAngle Yaw angle (degrees).
     */
    auto yaw(const Real& yawAngle) -> void;

private:
    Real roll_;
    Real pitch_;
    Real yaw_;
};

#include "RollPitchYaw.tpp"
