/*
 * @Author: your name
 * @Date: 2019-12-28 21:49:09
 * @LastEditTime : 2019-12-28 22:31:51
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /realtime_dect_loc/include/XYZRGBPCViewer.hpp
 */
#ifndef XYZRGBPOINT_CLOUD_VIEWER_HPP_
#define XYZRGBPOINT_CLOUD_VIEWER_HPP_

#include <opencv2/opencv.hpp>
#include <string>
#include <pcl/point_types.h> 
#include <pcl/point_cloud.h> // 点云
#include <pcl/visualization/cloud_viewer.h> // 可视化

#include "../include/2d_3d_merge.h"// 2d检测结果

class XYZRGBPCViewerImpl;

class XYZRGBPCViewer {
public:
    XYZRGBPCViewer();
    ~XYZRGBPCViewer();

    void show(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ptr, const std::string &windowName);
    //void show(Cluster& cluster, const std::string &windowName);
    bool isStopped(const std::string &windowName);

private:
    XYZRGBPCViewerImpl* impl; // 具体实现类
};

#endif // XYZRGBPOINT_CLOUD_VIEWER_HPP_
