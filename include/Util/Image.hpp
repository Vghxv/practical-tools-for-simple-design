#ifndef UTIL_IMAGE_HPP
#define UTIL_IMAGE_HPP

#include "pch.hpp" // IWYU pragma: export

#include <functional>
#include <glm/fwd.hpp>

#include "Core/Drawable.hpp"
#include "Core/Texture.hpp"

#include "Util/Logger.hpp"
#include "Util/Transform.hpp"

namespace Util {
class Image : public Core::Drawable {
public:
    Image(const std::string &filepath);

    glm::vec2 GetSize() const override { return m_Size; };

    void SetImage(const std::string &filepath);

    void Draw(const Util::Transform &transform, const float zIndex) override;

private:
    void InitProgram();
    void InitVertexArray();
    void InitUniformBuffer();

    static constexpr int UNIFORM_SURFACE_LOCATION = 0;

    static std::unique_ptr<Core::Program> s_Program;
    static std::unique_ptr<Core::VertexArray> s_VertexArray;
    static std::unique_ptr<Core::UniformBuffer<Core::Matrices>> s_UniformBuffer;

private:
    std::unique_ptr<Core::Texture> m_Texture = nullptr;

    std::string m_Path;
    glm::vec2 m_Size;
};
} // namespace Util

#endif