#include <tuple>

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "rotations/common.hpp"

SCENARIO("Normalize angle in degrees to range (-180, 180)")
{
    GIVEN("Various degree values")
    {
        // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
        auto [angle, expectedAngle] = GENERATE(
            std::tuple{0.0, 0.0}, std::tuple{32.0, 32.0}, std::tuple{180.0, 180.0},
            std::tuple{256.0, -104.0}, std::tuple{36256.0, -104.0}, std::tuple{-32.0, -32.0},
            std::tuple{-180.0, 180.0}, std::tuple{-256.0, 104.0}, std::tuple{-36256.0, 104.0}
        );
        // NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

        WHEN("Normalizing the angle")
        {
            const double normalizedAngle{normalizeDegrees(angle)};

            THEN("The normalized angle equals the expected value")
            {
                REQUIRE((normalizedAngle == Catch::Approx(expectedAngle)));
            }
        }
    }
}
SCENARIO("Normalize angle in radians to range (-pi, pi)")
{
    GIVEN("Various radian values")
    {
        // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
        auto [angle, expectedAngle] = GENERATE(
            std::tuple{0.0, 0.0}, std::tuple{std::numbers::pi / 3.0, std::numbers::pi / 3.0},
            std::tuple{std::numbers::pi, std::numbers::pi},
            std::tuple{4.0 * std::numbers::pi / 3.0, -2.0 * std::numbers::pi / 3.0},
            std::tuple{40.0 * std::numbers::pi / 3.0, -2.0 * std::numbers::pi / 3.0},
            std::tuple{-std::numbers::pi / 3.0, -std::numbers::pi / 3.0},
            std::tuple{-std::numbers::pi, std::numbers::pi},
            std::tuple{-4.0 * std::numbers::pi / 3.0, 2.0 * std::numbers::pi / 3.0},
            std::tuple{-40.0 * std::numbers::pi / 3.0, 2.0 * std::numbers::pi / 3.0}
        );
        // NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

        WHEN("Normalizing the angle")
        {
            const double normalizedAngle{normalizeRadians(angle)};

            THEN("The normalized angle equals the expected value")
            {
                REQUIRE((normalizedAngle == Catch::Approx(expectedAngle)));
            }
        }
    }
}

SCENARIO("Convert degrees to radians")
{
    GIVEN("Various degree values")
    {
        // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
        auto [degrees, expectedRadians] = GENERATE(
            std::tuple{0.0, 0.0}, std::tuple{30.0, std::numbers::pi / 6.0},
            std::tuple{60.0, std::numbers::pi / 3.0}, std::tuple{90.0, std::numbers::pi / 2.0},
            std::tuple{120.0, 2.0 * std::numbers::pi / 3.0},
            std::tuple{150.0, 5.0 * std::numbers::pi / 6.0}, std::tuple{180.0, std::numbers::pi},
            std::tuple{210.0, -5.0 * std::numbers::pi / 6.0},
            std::tuple{240.0, -2.0 * std::numbers::pi / 3.0},
            std::tuple{270.0, -std::numbers::pi / 2.0}, std::tuple{300.0, -std::numbers::pi / 3.0},
            std::tuple{330.0, -std::numbers::pi / 6.0}, std::tuple{360.0, 0.0},
            std::tuple{750.0, std::numbers::pi / 6.0}, std::tuple{-30.0, -std::numbers::pi / 6.0},
            std::tuple{-60.0, -std::numbers::pi / 3.0}, std::tuple{-90.0, -std::numbers::pi / 2.0},
            std::tuple{-120.0, -2.0 * std::numbers::pi / 3.0},
            std::tuple{-150.0, -5.0 * std::numbers::pi / 6.0}, std::tuple{-180.0, std::numbers::pi},
            std::tuple{-210.0, 5.0 * std::numbers::pi / 6.0},
            std::tuple{-240.0, 2.0 * std::numbers::pi / 3.0},
            std::tuple{-270.0, std::numbers::pi / 2.0}, std::tuple{-300.0, std::numbers::pi / 3.0},
            std::tuple{-330.0, std::numbers::pi / 6.0}, std::tuple{-360.0, 0.0},
            std::tuple{-750.0, -std::numbers::pi / 6.0}
        );
        // NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

        WHEN("Converting to radians")
        {
            const double radians{degreesToRadians(degrees)};

            THEN("The radians equal the expected value")
            {
                REQUIRE((radians == Catch::Approx(expectedRadians)));
            }
        }
    }
}

SCENARIO("Convert radians to degrees")
{
    GIVEN("Various radian values")
    {
        // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
        auto [radians, expectedDegrees] = GENERATE(
            std::tuple{0.0, 0.0}, std::tuple{std::numbers::pi / 6.0, 30.0},
            std::tuple{std::numbers::pi / 3.0, 60.0}, std::tuple{std::numbers::pi / 2.0, 90.0},
            std::tuple{2.0 * std::numbers::pi / 3.0, 120.0},
            std::tuple{5.0 * std::numbers::pi / 6.0, 150.0}, std::tuple{std::numbers::pi, 180.0},
            std::tuple{7.0 * std::numbers::pi / 6.0, -150.0},
            std::tuple{4.0 * std::numbers::pi / 3.0, -120.0},
            std::tuple{3.0 * std::numbers::pi / 2.0, -90.0},
            std::tuple{5.0 * std::numbers::pi / 3.0, -60.0},
            std::tuple{11.0 * std::numbers::pi / 6.0, -30.0},
            std::tuple{2.0 * std::numbers::pi, 0.0}, std::tuple{-std::numbers::pi / 6.0, -30.0},
            std::tuple{-std::numbers::pi / 3.0, -60.0}, std::tuple{-std::numbers::pi / 2.0, -90.0},
            std::tuple{-2.0 * std::numbers::pi / 3.0, -120.0},
            std::tuple{-5.0 * std::numbers::pi / 6.0, -150.0}, std::tuple{-std::numbers::pi, 180.0},
            std::tuple{-7.0 * std::numbers::pi / 6.0, 150.0},
            std::tuple{-4.0 * std::numbers::pi / 3.0, 120.0},
            std::tuple{-3.0 * std::numbers::pi / 2.0, 90.0},
            std::tuple{-5.0 * std::numbers::pi / 3.0, 60.0},
            std::tuple{-11.0 * std::numbers::pi / 6.0, 30.0},
            std::tuple{-2.0 * std::numbers::pi, 0.0}
        );
        // NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

        WHEN("Converting to degrees")
        {
            const double degrees{radiansToDegrees(radians)};

            THEN("The degrees equal the expected value")
            {
                REQUIRE((degrees == Catch::Approx(expectedDegrees)));
            }
        }
    }
}
