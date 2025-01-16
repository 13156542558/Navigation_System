# Navigation_System
# 一、选题背景
在现代信息技术迅速发展的背景下，图形用户界面（GUI）作为人机交互的重要媒介，其设计与实现的质量直接影响到软件的可用性和用户体验。本课题旨在解决如何利用Qt框架设计并实现一个高效、直观且具有良好交互性的图形用户界面。该界面需要展示地图数据中的点与边，并通过颜色变化反映边的流量状态，同时提供路径搜索和图示高亮功能，以增强用户对交通流量数据的直观理解。
# 二、方案论证(设计理念)
  设计原理
本设计方案的核心理念是实现一个交互式的图形界面应用程序，它能够高效地处理图形元素并计算路径。应用程序的设计注重用户体验、性能优化、数据安全性和系统的稳定性。
  方案选择
选择Qt框架作为开发平台，利用其跨平台特性和强大的图形处理能力。C++语言作为开发语言，因其高效的运行性能和对内存操作的精细控制。
  功能及其要求
 “图形展示”：用户可以通过`MyGraphicsView`类交互式地查看和操作图形元素。
 “路径计算”：应用程序能够计算最短路径和最近点，如在`Graph.h`中实现的`dij`函数。
 “实时更新”：路径和点的更新能够实时反映在界面上，如`MainWindow::updatePath`和`MainWindow::updatePoint`函数所示。

  系统安全性
输入验证：确保用户输入的坐标值在合法范围内，如`MainWindow::on_nearpt_clicked`中的条件检查。
异常处理：程序能够妥善处理运行时错误，避免因异常输入导致崩溃。

  数据完整性
数据备份：通过定时保存场景状态，防止数据丢失。
事务性操作：确保数据操作的原子性，维护数据一致性。

  应用运行环境及其性能要求
 “跨平台”：应用程序能够在Windows、Linux和macOS上运行。
 “性能优化”：通过多线程技术，如在`Graph.h`中实现的随机流量分配线程，提高计算效率。
 “资源管理”：程序设计考虑内存和处理器资源的有效利用，保证在资源受限的环境下也能稳定运行。

  设计方案特点
 “用户界面”：采用Qt Designer生成的界面，提供直观的用户交互体验。
 “事件驱动”：利用Qt的信号和槽机制，实现高效的事件响应。
 “多线程”：通过`MyThread`类实现线程分离，优化程序的并行处理能力。
 “图形处理 ”：自定义`MyGraphicsView`类，提供图形的缩放、平移等操作。

  安全性和完整性措施
 “输入校验”：在用户输入点坐标时，如`MainWindow::on_nearpt_clicked`，进行边界检查。
 “错误提示”：当用户操作不当或数据不完整时，提供明确的错误提示。
  总结
本设计方案旨在创建一个既能够满足高性能图形处理需求，又能提供良好用户体验的应用程序。通过综合考虑安全性、数据完整性和运行环境，确保了系统的稳定性和可靠性。
