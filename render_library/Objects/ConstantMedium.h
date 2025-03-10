#pragma once

#include "Interfaces/IHittable.h"
class IMaterial;
class ITexture;


class ConstantMedium : public IHittable {
private:
    // Data
    std::shared_ptr<IHittable> _boundary = nullptr;
    std::shared_ptr<IMaterial> _phase_function = nullptr;
    rreal _neg_inv_intensity = 0;

public:
    explicit ConstantMedium(
        const std::shared_ptr<IHittable> &boundary,
        const rreal density,
        const std::shared_ptr<ITexture> &phase
    ) NOEXCEPT;

    explicit ConstantMedium(
        const std::shared_ptr<IHittable> &boundary,
        const rreal density,
        const Vec3 &clr
    ) NOEXCEPT;

    std::shared_ptr<IHittable> deep_copy() const NOEXCEPT override;

    bool hit(RandomGenerator &rng, const Ray &r, const rreal t_min, const rreal t_max, HitRecord &rec) const NOEXCEPT override;
    bool bounding_box(const rreal t0, const rreal t1, AABB &output_box) const NOEXCEPT override;

    rreal pdf_value(
        [[maybe_unused]] RandomGenerator &rng,
        [[maybe_unused]] const Vec3 &origin,
        [[maybe_unused]] const Vec3 &v
    ) const NOEXCEPT override {
        return 0;
    }

    Vec3 random(
        [[maybe_unused]] RandomGenerator &rng,
        [[maybe_unused]] const Vec3 &origin
    ) const NOEXCEPT override {
        return Vec3(1, 0, 0);
    }
};
