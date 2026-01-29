#include <tuple>

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "rotations/RollPitchYaw.hpp"

SCENARIO("Define attitude angles and check normalization")
{
    GIVEN("Various attitude angles")
    {
        // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
        auto [roll, pitch, yaw, expectedRoll, expectedPitch, expectedYaw] = GENERATE(
            // In-range cases
            std::tuple{30.0, 45.0, 60.0, 30.0, 45.0, 60.0},
            std::tuple{-30.0, -45.0, -60.0, -30.0, -45.0, -60.0},
            std::tuple{0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
            std::tuple{180.0, 180.0, 180.0, 180.0, 180.0, 180.0},
            // Out-of-range cases
            std::tuple{225.0, 270.0, 315.0, -135.0, -90.0, -45.0},
            std::tuple{-225.0, -270.0, -315.0, 135.0, 90.0, 45.0},
            std::tuple{-180.0, -180.0, -180.0, 180.0, 180.0, 180.0},
            std::tuple{36225.0, 36270.0, 36315.0, -135.0, -90.0, -45.0},
            std::tuple{-36225.0, -36270.0, -36315.0, 135.0, 90.0, 45.0}
        );
        // NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

        WHEN("Instantiating RollPitchYaw")
        {
            const RollPitchYaw<double> rollPitchYaw{roll, pitch, yaw};
            const double computedRoll{rollPitchYaw.roll()};
            const double computedPitch{rollPitchYaw.pitch()};
            const double computedYaw{rollPitchYaw.yaw()};

            THEN("The roll, pitch and yaw equal the expected values")
            {
                REQUIRE((computedRoll == Catch::Approx(expectedRoll)));
                REQUIRE((computedPitch == Catch::Approx(expectedPitch)));
                REQUIRE((computedYaw == Catch::Approx(expectedYaw)));
            }
        }
    }
}
