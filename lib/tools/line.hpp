#pragma once

#include "../common/i_tool.hpp"

class Line : public ITool {
   private:
    int m_width;

   public:
    explicit Line(int width);

    void onMouseDown(int row, int col) override;

    void onMouseMove(int row, int col) override;

    void onMouseUp(int row, int col) override;
};
