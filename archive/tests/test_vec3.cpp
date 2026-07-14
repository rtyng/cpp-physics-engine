#include <cmath>

#include <gtest/gtest.h>

#include "math-core.hpp"

namespace
{
constexpr double tolerance = 1.0e-12;

/*
Compare two Vec3 objects component by component.

EXPECT_NEAR is used because many vector operations involve floating-point
division or square roots, which may not produce exact binary representations.
*/
void expectVec3Near(
    const Vec3& actual,
    const Vec3& expected,
    const double allowedError = tolerance)
{
    EXPECT_NEAR(actual.x, expected.x, allowedError);
    EXPECT_NEAR(actual.y, expected.y, allowedError);
    EXPECT_NEAR(actual.z, expected.z, allowedError);
}
}

// ---------------------------------------------------------------------------
// Construction
// ---------------------------------------------------------------------------

TEST(Vec3Construction, DefaultConstructorInitializesComponentsToZero)
{
    const Vec3 vector{};

    EXPECT_DOUBLE_EQ(vector.x, 0.0);
    EXPECT_DOUBLE_EQ(vector.y, 0.0);
    EXPECT_DOUBLE_EQ(vector.z, 0.0);
}

TEST(Vec3Construction, ComponentConstructorStoresPositiveValues)
{
    const Vec3 vector{1.0, 2.0, 3.0};

    EXPECT_DOUBLE_EQ(vector.x, 1.0);
    EXPECT_DOUBLE_EQ(vector.y, 2.0);
    EXPECT_DOUBLE_EQ(vector.z, 3.0);
}

TEST(Vec3Construction, ComponentConstructorStoresNegativeAndFractionalValues)
{
    const Vec3 vector{-1.25, 2.5, -3.75};

    EXPECT_DOUBLE_EQ(vector.x, -1.25);
    EXPECT_DOUBLE_EQ(vector.y, 2.5);
    EXPECT_DOUBLE_EQ(vector.z, -3.75);
}

// ---------------------------------------------------------------------------
// Scalar multiplication
// ---------------------------------------------------------------------------

TEST(Vec3ScalarMultiplication, MultipliesEveryComponentByPositiveScalar)
{
    const Vec3 vector{1.0, -2.0, 3.5};

    const Vec3 result = vector * 4.0;

    expectVec3Near(result, Vec3{4.0, -8.0, 14.0});
}

TEST(Vec3ScalarMultiplication, MultipliesEveryComponentByNegativeScalar)
{
    const Vec3 vector{1.0, -2.0, 3.0};

    const Vec3 result = vector * -2.0;

    expectVec3Near(result, Vec3{-2.0, 4.0, -6.0});
}

TEST(Vec3ScalarMultiplication, MultiplicationByZeroProducesZeroVector)
{
    const Vec3 vector{7.0, -4.0, 2.0};

    const Vec3 result = vector * 0.0;

    expectVec3Near(result, Vec3{});
}

TEST(Vec3ScalarMultiplication, MultiplicationByOnePreservesVector)
{
    const Vec3 vector{7.0, -4.0, 2.0};

    const Vec3 result = vector * 1.0;

    expectVec3Near(result, vector);
}

TEST(Vec3ScalarMultiplication, DoesNotModifyOriginalVector)
{
    const Vec3 vector{1.0, 2.0, 3.0};

    [[maybe_unused]] const Vec3 result = vector * 10.0;

    expectVec3Near(vector, Vec3{1.0, 2.0, 3.0});
}

// ---------------------------------------------------------------------------
// Compound addition
// ---------------------------------------------------------------------------

TEST(Vec3CompoundAddition, AddsComponentsToCurrentVector)
{
    Vec3 vector{1.0, 2.0, 3.0};
    const Vec3 other{4.0, 5.0, 6.0};

    vector += other;

    expectVec3Near(vector, Vec3{5.0, 7.0, 9.0});
}

TEST(Vec3CompoundAddition, AddingZeroLeavesVectorUnchanged)
{
    Vec3 vector{1.0, -2.0, 3.0};

    vector += Vec3{};

    expectVec3Near(vector, Vec3{1.0, -2.0, 3.0});
}

TEST(Vec3CompoundAddition, SupportsNegativeComponents)
{
    Vec3 vector{5.0, 5.0, 5.0};

    vector += Vec3{-2.0, -3.0, -4.0};

    expectVec3Near(vector, Vec3{3.0, 2.0, 1.0});
}

// ---------------------------------------------------------------------------
// Compound subtraction
// ---------------------------------------------------------------------------

TEST(Vec3CompoundSubtraction, SubtractsComponentsFromCurrentVector)
{
    Vec3 vector{10.0, 8.0, 6.0};
    const Vec3 other{1.0, 2.0, 3.0};

    vector -= other;

    expectVec3Near(vector, Vec3{9.0, 6.0, 3.0});
}

TEST(Vec3CompoundSubtraction, SubtractingZeroLeavesVectorUnchanged)
{
    Vec3 vector{1.0, -2.0, 3.0};

    vector -= Vec3{};

    expectVec3Near(vector, Vec3{1.0, -2.0, 3.0});
}

TEST(Vec3CompoundSubtraction, SubtractingVectorFromItselfProducesZero)
{
    Vec3 vector{4.0, -5.0, 6.0};
    const Vec3 copy = vector;

    vector -= copy;

    expectVec3Near(vector, Vec3{});
}

// ---------------------------------------------------------------------------
// Compound scalar multiplication
// ---------------------------------------------------------------------------

TEST(Vec3CompoundScalarMultiplication, ModifiesEveryComponent)
{
    Vec3 vector{1.0, -2.0, 3.0};

    vector *= 5.0;

    expectVec3Near(vector, Vec3{5.0, -10.0, 15.0});
}

TEST(Vec3CompoundScalarMultiplication, MultiplicationByZeroClearsVector)
{
    Vec3 vector{1.0, -2.0, 3.0};

    vector *= 0.0;

    expectVec3Near(vector, Vec3{});
}

TEST(Vec3CompoundScalarMultiplication, MultiplicationByNegativeOneInvertsVector)
{
    Vec3 vector{1.0, -2.0, 3.0};

    vector *= -1.0;

    expectVec3Near(vector, Vec3{-1.0, 2.0, -3.0});
}

// ---------------------------------------------------------------------------
// Square magnitude
// ---------------------------------------------------------------------------

TEST(Vec3SquareMagnitude, ZeroVectorHasZeroSquareMagnitude)
{
    const Vec3 vector{};

    EXPECT_DOUBLE_EQ(vector.squareMagnitude(), 0.0);
}

TEST(Vec3SquareMagnitude, ComputesSumOfSquaredComponents)
{
    const Vec3 vector{2.0, 3.0, 6.0};

    EXPECT_DOUBLE_EQ(vector.squareMagnitude(), 49.0);
}

TEST(Vec3SquareMagnitude, IsUnaffectedByComponentSigns)
{
    const Vec3 positive{2.0, 3.0, 6.0};
    const Vec3 negative{-2.0, -3.0, -6.0};

    EXPECT_DOUBLE_EQ(
        positive.squareMagnitude(),
        negative.squareMagnitude());
}

TEST(Vec3SquareMagnitude, DoesNotModifyVector)
{
    const Vec3 vector{2.0, 3.0, 6.0};

    [[maybe_unused]] const double result = vector.squareMagnitude();

    expectVec3Near(vector, Vec3{2.0, 3.0, 6.0});
}

// ---------------------------------------------------------------------------
// Magnitude
// ---------------------------------------------------------------------------

TEST(Vec3Magnitude, ZeroVectorHasZeroMagnitude)
{
    const Vec3 vector{};

    EXPECT_DOUBLE_EQ(vector.magnitude(), 0.0);
}

TEST(Vec3Magnitude, ComputesKnownThreeFourFiveMagnitude)
{
    const Vec3 vector{3.0, 4.0, 0.0};

    EXPECT_DOUBLE_EQ(vector.magnitude(), 5.0);
}

TEST(Vec3Magnitude, ComputesMagnitudeUsingAllThreeComponents)
{
    const Vec3 vector{2.0, 3.0, 6.0};

    EXPECT_DOUBLE_EQ(vector.magnitude(), 7.0);
}

TEST(Vec3Magnitude, IsUnaffectedByComponentSigns)
{
    const Vec3 positive{2.0, 3.0, 6.0};
    const Vec3 negative{-2.0, -3.0, -6.0};

    EXPECT_DOUBLE_EQ(
        positive.magnitude(),
        negative.magnitude());
}

TEST(Vec3Magnitude, MatchesSquareRootOfSquareMagnitude)
{
    const Vec3 vector{1.25, -7.5, 3.0};

    EXPECT_NEAR(
        vector.magnitude(),
        std::sqrt(vector.squareMagnitude()),
        tolerance);
}

TEST(Vec3Magnitude, DoesNotModifyVector)
{
    const Vec3 vector{2.0, 3.0, 6.0};

    [[maybe_unused]] const double result = vector.magnitude();

    expectVec3Near(vector, Vec3{2.0, 3.0, 6.0});
}

// ---------------------------------------------------------------------------
// Normalize
// ---------------------------------------------------------------------------

TEST(Vec3Normalize, ProducesUnitLengthVector)
{
    Vec3 vector{3.0, 4.0, 0.0};

    vector.normalize();

    EXPECT_NEAR(vector.magnitude(), 1.0, tolerance);
}

TEST(Vec3Normalize, ProducesExpectedComponents)
{
    Vec3 vector{3.0, 4.0, 0.0};

    vector.normalize();

    expectVec3Near(vector, Vec3{0.6, 0.8, 0.0});
}

TEST(Vec3Normalize, PreservesDirectionForNegativeComponents)
{
    Vec3 vector{-3.0, 0.0, 4.0};

    vector.normalize();

    expectVec3Near(vector, Vec3{-0.6, 0.0, 0.8});
}

TEST(Vec3Normalize, LeavesZeroVectorUnchanged)
{
    Vec3 vector{};

    vector.normalize();

    expectVec3Near(vector, Vec3{});
}

TEST(Vec3Normalize, LeavesUnitVectorUnchanged)
{
    Vec3 vector{1.0, 0.0, 0.0};

    vector.normalize();

    expectVec3Near(vector, Vec3{1.0, 0.0, 0.0});
}

TEST(Vec3Normalize, NormalizingTwiceProducesSameResult)
{
    Vec3 vector{3.0, 4.0, 0.0};

    vector.normalize();
    const Vec3 onceNormalized = vector;

    vector.normalize();

    expectVec3Near(vector, onceNormalized);
}

// ---------------------------------------------------------------------------
// Unit
// ---------------------------------------------------------------------------

TEST(Vec3Unit, ReturnsNormalizedCopy)
{
    const Vec3 vector{0.0, 3.0, 4.0};

    const Vec3 result = vector.unit();

    expectVec3Near(result, Vec3{0.0, 0.6, 0.8});
    EXPECT_NEAR(result.magnitude(), 1.0, tolerance);
}

TEST(Vec3Unit, DoesNotModifyOriginalVector)
{
    const Vec3 vector{0.0, 3.0, 4.0};

    [[maybe_unused]] const Vec3 result = vector.unit();

    expectVec3Near(vector, Vec3{0.0, 3.0, 4.0});
}

TEST(Vec3Unit, ReturnsZeroForZeroVector)
{
    const Vec3 vector{};

    const Vec3 result = vector.unit();

    expectVec3Near(result, Vec3{});
}

TEST(Vec3Unit, ReturnsEquivalentCopyForUnitVector)
{
    const Vec3 vector{0.0, 1.0, 0.0};

    const Vec3 result = vector.unit();

    expectVec3Near(result, vector);
}

// ---------------------------------------------------------------------------
// Clear
// ---------------------------------------------------------------------------

TEST(Vec3Clear, ResetsAllComponentsToZero)
{
    Vec3 vector{1.0, -2.0, 3.0};

    vector.clear();

    EXPECT_DOUBLE_EQ(vector.x, 0.0);
    EXPECT_DOUBLE_EQ(vector.y, 0.0);
    EXPECT_DOUBLE_EQ(vector.z, 0.0);
}

TEST(Vec3Clear, LeavesZeroVectorAtZero)
{
    Vec3 vector{};

    vector.clear();

    expectVec3Near(vector, Vec3{});
}

TEST(Vec3Clear, ProducesZeroMagnitude)
{
    Vec3 vector{1.0, -2.0, 3.0};

    vector.clear();

    EXPECT_DOUBLE_EQ(vector.magnitude(), 0.0);
    EXPECT_DOUBLE_EQ(vector.squareMagnitude(), 0.0);
}

// ---------------------------------------------------------------------------
// Invert
// ---------------------------------------------------------------------------

TEST(Vec3Invert, NegatesEveryComponent)
{
    Vec3 vector{1.0, -2.0, 3.0};

    vector.invert();

    expectVec3Near(vector, Vec3{-1.0, 2.0, -3.0});
}

TEST(Vec3Invert, LeavesZeroVectorUnchanged)
{
    Vec3 vector{};

    vector.invert();

    expectVec3Near(vector, Vec3{});
}

TEST(Vec3Invert, ApplyingTwiceRestoresOriginalVector)
{
    Vec3 vector{1.25, -2.5, 3.75};
    const Vec3 original = vector;

    vector.invert();
    vector.invert();

    expectVec3Near(vector, original);
}

TEST(Vec3Invert, DoesNotChangeMagnitude)
{
    Vec3 vector{1.0, -2.0, 3.0};
    const double originalMagnitude = vector.magnitude();

    vector.invert();

    EXPECT_NEAR(vector.magnitude(), originalMagnitude, tolerance);
}

// ---------------------------------------------------------------------------
// Add scaled vector
// ---------------------------------------------------------------------------

TEST(Vec3AddScaledVector, AddsVectorMultipliedByScale)
{
    Vec3 position{1.0, 2.0, 3.0};
    const Vec3 velocity{4.0, 6.0, 8.0};

    position.addScaledVector(velocity, 0.5);

    expectVec3Near(position, Vec3{3.0, 5.0, 7.0});
}

TEST(Vec3AddScaledVector, ZeroScaleLeavesCurrentVectorUnchanged)
{
    Vec3 position{1.0, 2.0, 3.0};
    const Vec3 original = position;
    const Vec3 velocity{100.0, 200.0, 300.0};

    position.addScaledVector(velocity, 0.0);

    expectVec3Near(position, original);
}

TEST(Vec3AddScaledVector, NegativeScaleSubtractsScaledVector)
{
    Vec3 position{10.0, 20.0, 30.0};
    const Vec3 velocity{1.0, 2.0, 3.0};

    position.addScaledVector(velocity, -2.0);

    expectVec3Near(position, Vec3{8.0, 16.0, 24.0});
}

TEST(Vec3AddScaledVector, DoesNotModifyInputVector)
{
    Vec3 position{1.0, 2.0, 3.0};
    const Vec3 velocity{4.0, 6.0, 8.0};

    position.addScaledVector(velocity, 0.5);

    expectVec3Near(velocity, Vec3{4.0, 6.0, 8.0});
}

TEST(Vec3AddScaledVector, MatchesManualComponentCalculation)
{
    Vec3 vector{2.0, 4.0, 6.0};
    const Vec3 derivative{3.0, 5.0, 7.0};
    constexpr double scale = 0.25;

    vector.addScaledVector(derivative, scale);

    expectVec3Near(
        vector,
        Vec3{
            2.0 + 3.0 * scale,
            4.0 + 5.0 * scale,
            6.0 + 7.0 * scale
        });
}