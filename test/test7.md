% 核心类介绍 
% hdm258i@gmail.com
% 2013-04-10
% 基础, webapp框架 

## 前言

rocket提供了一套框架类，本文介绍类库构成、继承关系和接口。

## 核心类构成

框架提供了9个核心类，分别是：

* rocket.router
* rocket.model
* rocket.collection
* rocket.baseview
* rocket.pageview
* rocket.subview
* rocket.globalview
* rocket.subpagemanager
* rocket.subpageview

类的继承关系以及封装类与第三方MVC类库Backbbone的关系如下图：

![核心类层次结构](./img/core_classes_hierarchy.png)

## 核心类使用简单说明 

* app路由：通过继承rocket.router，提供routes、pageOrder、pageTransition等配置，编写route handler

        (function($) {

        rocket.router.vs = rocket.router.extend({

            // 路由配置
            routes: {
                '': 'index'
                ,'list/:type': 'list'
            }

            // 页面切换顺序配置
            ,pageOrder: [
                'index'
                , 'list'
            ]

            // 位置记忆，默认为false，不进行位置记忆
            ,enablePositionRestore: true

            // 默认页面切换动画
            ,defaultPageTransition: 'slide'

            // 页面切换动画配置
            ,pageTransition: {

                'index-list': 'fade'

            }


            ,index: function(type) {
                if(!type) {
                    type = 'focus';
                }

                this.doAction('index', {
                        type: decodeURIComponent(type)
                });
            }

            ,list: function(type) {
                this.doAction('list', {
                    type: decodeURIComponent(type)
                });
            }

        }); 

        })(Zepto);

* 页面视图控制器，通过继承rocket.pageview

        (function($) {

        rocket.pageview.index = rocket.pageview.extend({
            el: "#index_page"

            ,init: function(options){
                var me = this;

                // 创建header子视图
                me.setup(new rocket.subview.index_header(options, me));

                // 创建content子视图
                me.setup(new rocket.subview.index_content(options, me));
            }

            ...

        });

        })(Zepto);



* 页面子视图控制器，通过继承rocket.subview；**不直接使用rocket.baseview**

        (function($) {

        rocket.subview.index_content = rocket.subview.extend({
            el: "#index_page_content"

            ,init: function(options){
                var me = this;

                me.setup(new rocket.subview.index_content_list(
                    $.extend({}, options),
                    me
                ));

                me.setup(new rocket.subview.index_content_tuiguang(
                    $.extend({}, options),
                    me
                ));
            }

            ,registerEvents: function(){
                var me = this, ec = me.ec;
                ec.on("pagebeforechange", me.onpagebeforechange, me);
            }

            ,onpagebeforechange: function(params){
                var me = this, 
                    from = params.from,
                    to = params.to,
                    param = params.params;

                if(to == me.ec) {
                    me.$el.show();
                }
            }

        });

        })(Zepto);


* 页面模型，通过继承rocket.model或rocket.collection 

        (function($){

        rocket.collection.index_news = rocket.collection.extend({

            initialize: function(models, options){
                var me = this;
            }

            ,url: function(){
                return '/index?' + (new Date()).getTime();
            }

            ,parse: function(resp, xhr){
                return resp.content;
            }

        });

        })(Zepto);

* 全局视图控制器，通过继承rocket.globalview，可直接相应路由事件，持有页面视图控制器，可按需向页面控视图控制器发送事件。

        (function($){
         
        rocket.globalview.sidenav = rocket.globalview.extend({
             
            el: '#sidenav_globalview'

            ,init: function(options){
                var me = this;

                ...
            }

            ,registerEvents: function(){
                var me = this, ec = me.ec;

                ec.on('routechange', me.onroutechange, me);
                ...
            }

            ,onroutechange: function(params){
                var me = this,
                    from = params.from || null,
                    to = params.to || null,
                    fromAction = from && from.action || null,
                    toAction = to && to.action || null,
                    pageviews = params.pageviews;

                ...
            }

            ...

        });

        })(Zepto);


* 子页面管理器，是rocket.subpagemanager的实例，管理子页面的创建、回收、动画切换效果等。使用时rocket.baseview子类通过调用getSubpageManager()方法获取

        (function($){

        rocket.subview.search_content = rocket.subview.extend({

            ...

            ,init: function(options){
                var me = this,
                    subView,
                    spm;

                spm = me.getSubpageManager({
                    subpageClass: rocket.subpageview.search_subpage
                    ,maxSubpages: 2
                });

                subView = new rocket.subpageview.search_subpage(
                    $.extend({}, options)
                    ,me
                );

                me.append(subView);
                spm.registerSubpage(me.featureString, subView);

            }

            ...
            
        });

        })(Zepto);

* 子页面视图控制器，通过继承rocket.subpageview，作为子页面的事件中心，其子视图控制器可以通过subec引用

        (function($){

        rocket.subpageview.search_subpage = rocket.subpageview.extend({

            className: 'search-page-subpage'

            ,noresultTemplate: _.template($('#template_search_subpage_noresult').text())

            ,init: function(options){
                var me = this;

                ...
            }

            ,registerEvents: function(){
                var me = this,
                    ec = me.ec;

                ec.on('keydown', me.onkeydown, me);
            }

            ,unregisterEvents: function(){
                var me = this,
                    ec = me.ec;

                ec.off('keydown', me.onkeydown, me);
            }

            ,onsubpagebeforechange: function(params){
                var me = this, 
                    from = params.from,
                    to = params.to,
                    param = params.params,
                    featureString = me.getFeatureString(param);

                ...
            }

            ,onkeydown: function(params){
                var me = this,
                    e = params.event,
                    targetSubpage = params.targetSubpage,
                    key = e.which,
                    hit = false;
                
                ...
            }

        });
         
        })(Zepto);

