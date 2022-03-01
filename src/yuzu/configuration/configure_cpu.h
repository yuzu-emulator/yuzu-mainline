// Copyright 2020 yuzu Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include <QWidget>
#include "common/settings.h"

namespace Core {
class System;
}

namespace ConfigurationShared {
enum class CheckState;
}

namespace Ui {
class ConfigureCpu;
}

class ConfigureCpu : public QWidget {
    Q_OBJECT

public:
    explicit ConfigureCpu(const Core::System& system_, QWidget* parent = nullptr);
    ~ConfigureCpu() override;

    void ApplyConfiguration();
    void SetConfiguration();

private:
    void changeEvent(QEvent* event) override;
    void RetranslateUI();

    void UpdateGroup(int index);

    void SetupPerGameUI();

    std::unique_ptr<Ui::ConfigureCpu> ui;

    ConfigurationShared::CheckState cpuopt_unsafe_unfuse_fma;
    ConfigurationShared::CheckState cpuopt_unsafe_reduce_fp_error;
    ConfigurationShared::CheckState cpuopt_unsafe_ignore_standard_fpcr;
    ConfigurationShared::CheckState cpuopt_unsafe_inaccurate_nan;
    ConfigurationShared::CheckState cpuopt_unsafe_fastmem_check;
    ConfigurationShared::CheckState cpuopt_unsafe_ignore_global_monitor;

    const Core::System& system;
};
