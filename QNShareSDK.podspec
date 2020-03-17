#
# Be sure to run `pod lib lint QNShareSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
s.name             = 'QNShareSDK'
s.version          = '0.0.1'
s.summary          = '轻牛旗下共享秤SDK'

s.description      = '支持共享秤二维码数据解析'

s.homepage         = 'https://github.com/YolandaQingniu/SDK-Share-iOS'
s.license          = { :type => 'MIT', :file => 'LICENSE' }
s.author           = { 'service@qnniu.com' => 'service@qnniu.com' }
s.source           = { :git => 'https://github.com/YolandaQingniu/SDK-Share-iOS.git', :tag => s.version }

s.ios.deployment_target = '8.0'

s.vendored_frameworks = ['QNShareSDK-demo/QNShareSDK/QNShareDevice.framework']
s.xcconfig = {'BITCODE_GENERATION_MODE' => 'bitcode'}

end
