#pragma once

#include <maya/MString.h>
#include <maya/MStatus.h>
#include <vector>

class MObject;
class MIntArray;
class MDoubleArray;
class MDagPath;
class M3dView;
class QWidget;

namespace mayaMVG {

class MVGMenu;
class MVGCamera;

struct MVGMayaUtil {
	// window
	static MStatus createMVGWindow();
	static MStatus deleteMVGWindow();
	static QWidget* getMVGWindow();
	// window menu
	static QWidget* getMVGMenuLayout();
	// viewports
	static QWidget* getMVGLeftViewportLayout();
	static QWidget* getMVGRightViewportLayout();
	static MStatus setFocusOnLeftView();
	static MStatus setFocusOnRightView();
	static bool isMVGView(const M3dView & view);
	static bool isActiveView(const M3dView & view);
	static bool mouseUnderView(const M3dView & view);
	// context
	static MStatus createMVGContext();
	static MStatus deleteMVGContext();
	static MStatus activeContext(); 
	
	static MStatus activeSelectionContext();
	// cameras
	static MStatus getMVGLeftCamera(MDagPath& path);
	static MStatus setMVGLeftCamera(const MVGCamera& camera);
	static MStatus getMVGRightCamera(MDagPath& path);
	static MStatus setMVGRightCamera(const MVGCamera& camera);
	// maya selection
	static MStatus addToMayaSelection(MString objectName);
	static MStatus clearMayaSelection();
	// attributes
	static MStatus getIntArrayAttribute(const MObject&, const MString&, MIntArray&, bool=false);
	static MStatus setIntArrayAttribute(const MObject&, const MString&, const MIntArray&, bool=false);
	static MStatus getIntAttribute(const MObject&, const MString&, int&, bool=false);
	static MStatus setIntAttribute(const MObject&, const MString&, const int&, bool=false);
	static MStatus getDoubleArrayAttribute(const MObject&, const MString&, MDoubleArray&, bool=false);
	static MStatus setDoubleArrayAttribute(const MObject&, const MString&, const MDoubleArray&, bool=false);
	static MStatus findConnectedNodes(const MObject&, const MString&, std::vector<MObject>&);
	// nodes
	static MStatus getObjectByName(const MString&, MObject&);
	static MStatus getDagPathByName(const MString&, MDagPath&);
	// environment
	static MString getEnv(const MString&);
	static MString getModulePath();
	
	// filedialog
	static MStatus openFileDialog(MString& directory);
};

} // mayaMVG