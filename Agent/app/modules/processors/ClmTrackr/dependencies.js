/*****************************************************************\
** Clmtrackr emotion recognition module dependencies
\*****************************************************************/

mainframe.addModuleDependency(new ModuleDependency(moduleDirectory+"/processors/ClmTrackr/models", "model_pca_20_svm_emotionDetection.js", "ClmTrackr"));
mainframe.addModuleDependency(new ModuleDependency(moduleDirectory+"/processors/ClmTrackr/js", "clmtrackr.min.js", "ClmTrackr"));
mainframe.addModuleDependency(new ModuleDependency(moduleDirectory+"/processors/ClmTrackr/js", "utils.js", "ClmTrackr"));
mainframe.addModuleDependency(new ModuleDependency(moduleDirectory+"/processors/ClmTrackr/js", "d3.min.js", "ClmTrackr"));
mainframe.addModuleDependency(new ModuleDependency(moduleDirectory+"/processors/ClmTrackr/js", "emotion_classifier.js", "ClmTrackr"));
mainframe.addModuleDependency(new ModuleDependency(moduleDirectory+"/processors/ClmTrackr/js", "emotionmodel.js", "ClmTrackr"));
