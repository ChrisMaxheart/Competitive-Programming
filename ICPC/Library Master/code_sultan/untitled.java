

public static String testableHtml(PageData pageData, boolean includeSuiteSetup) throws Exception
	{
		WikiPage wikiPage = pageData.getWikiPage();
		StringBuffer buffer = new StringBuffer();
		if(pageData.hasAttribute("Test"))
		{
			if (includeSuiteSetup) 
			{
				WikiPage suiteSetup = PageCrawlerImpl.getInheritedPage(SuiteResponder.SUITE_SETUP_NAME, wikiPage);
				if (suiteSetup != null) {
					WikiPagePath pagePath = suiteSetup.getPageCrawler().getFullPath(suiteSetup);
					String pagePathName = PathParser.render(pagePath);
					buffer.append("!include -setup .").append(pagePathName).append("\n");
				}
			}
			WikiPage setup = PageCrawlerImpl.getInheritedPage("SetUp", wikiPage);
			if (setup != null)
			{
				WikiPagePath setupPath = wikiPage.getPageCrawler().getFullPath(setup);
				String setupPathName = PathParser.render(setupPath);
				buffer.append("!include -setup .").append(setupPathName).append("\n");
			}
		}
		buffer.append(pageData.getContent());
		if(pageData.hasAttribute("Test"))
		{
			WikiPage teardown = PageCrawlerImpl.getInheritedPage("TearDown", wikiPage);
			if(teardown != null)
			{
				WikiPagePath tearDownPath = wikiPage.getPageCrawler().getFullPath(teardown);
				String tearDownPathName = PathParser.render(tearDownPath);
				buffer.append("\n").append("!include -teardown .").append(tearDownPathName).append("\n");
			}
            if (includeSuiteSetup)
            {
               WikiPage suiteTeardown = PageCrawlerImpl.getInheritedPage(SuiteResponder.SUITE_TEARDOWN_NAME, wikiPage);
               if (suiteTeardown != null)
               {
                  WikiPagePath pagePath = suiteTeardown.getPageCrawler().getFullPath(suiteTeardown);
                  String pagePathName = PathParser.render(pagePath);
                  buffer.append("!include -teardown .").append(pagePathName).append("\n");
               }
            }
        }
		pageData.setContent(buffer.toString());
		return pageData.getHtml();
	}



public List<int[]> getFlaggedCells() {
	List<int[]> flaggedCells = new ArrayList<int[]>();
	for (int[] cell : gameBoard)
		if (cell.isFlagged())
			flaggedCells.add(cell);
	return flaggedCells; 
}


public void holyHandGrenade() {
	// Some codes are here
}

public void deleteItems() {
	// Some codes are here
}

accountList  // must be a list!


XYZControllerForEfficientHandlingOfStrings
XYZControllerForEfficientStorageOfStrings


int a = 1;
if (O == l)
	a = O1;
else
	l = 01;


a1
a2
a3


nameString
name

getActiveAccount();
getActiveAccounts();
getActiveAccountInfo();


class Customer 
class CustomerObject


theMessage
message


class DtaRcrd102 {
	private Date genymdhms;
	private Date modymdhms;
	private final String pszqint = "102";
	// A lot of stuffs
}

class Customer {
	private Date generationTimestamp;
	private Date modificationTimestamp;
	private final String recordId = "102";
	// A lot of stuffs
}

for (int j = 0; j < 34; j++) {
	s += (t[j] * 4) / 5;
}

int realDaysPerIdealDay = 4;
int WORK_DAYS_PER_WEEK = 5;
int sum = 0;
for (int j = 0; j < NUMBER_OF_TASKS; j++) {
	int realTaskDays = taskEstimate[j] * realDaysPerIdealDay;
	int realTaskWeeks = realTaskDays / WORK_DAYS_PER_WEEK;
	sum += realTaskWeeks;
}




String state;


String firstName, lastName, street, city, state;
int houseNumber, zipcode;


class houseAddress {
	String firstName, lastName, street, city, state;
	int houseNumber, zipcode;
}

public static String renderPageWithSetupsAndTeardowns(PageData pageData, boolean isSuite) throws Exception {
	if (isTestPage(pageData))
		includeSetupAndTeardownPages(pageData, isSuite);
	return pageData.getHtml();
}
private String render(boolean isSuite) throws Exception {
    this.isSuite = isSuite;
    if (isTestPage())
      includeSetupAndTeardownPages();
    return pageData.getHtml();
  }

private boolean isTestPage() throws Exception {
	return pageData.hasAttribute("Test");
}

private void includeSetupAndTeardownPages() throws Exception {
    includeSetupPages();
    includePageContent();
    includeTeardownPages();
    updatePageContent();
}

private void includeSetupPages() throws Exception {
    if (isSuite)
      	includeSuiteSetupPage();
    includeSetupPage();
}


includeSetupPage();
includeSetupPageInto(newPageContent);



assertEquals(expected, actual);


assertExpectedEqualsActual(expected, actual);


boolean isSuite = true;
render(isSuite);

private String render(boolean isSuite){
	if (isSuite) {
	    // codes
	}
	// codes
}




boolean isSuite = true;
if (isSuite) {
	renderForSuite();
} else {
	renderForSingleTest();
}

private String renderForSuite() {
	// codes
}

private String renderForSingleTest() {
	// codes
}



Circle makeCircle(double x, double y, double radius);

Circle makeCircle(Point center, double radius);


public class UserValidator {
	private Cryptographer cryptographer;

	public boolean checkPassword(String userName, String password) {
		User user = UserGateway.findByName(userName);
		if (user != User.NULL) {
			String codedPhrase = user.getPhraseEncodedByPassword();
			String phrase = cryptographer.decrypt(codedPhrase, password);
			if ("Valid Password".equals(phrase)) {
				Session.initialize();
				return true;
			}
		}
		return false;
	}
}


appendFooter(s);


public void appendFooter(StringBuffer report) {};


report.appendFooter();


public boolean set(String attribute, String value) {};

if (set("username", "unclebob"))


if (attributeExists("username")) {
	setAttribute("username", "unclebob");
}




// Check to see if the employee is eligible for full benefits
if ((employee.flags & HOURLY_FLAG) && employee.age > 65) {}


if (employee.isEligibleForFullBenefits()) {}


// format matched kk:mm:ss EEE, MMMM, dd, yyyy
Patter timeMatcher = Pattern.compile("\\d*:\\d*:\\d* \\w*, \\w* \\d*, \\d*");


public void testConcurrentAddWidgets() throws Exception {
	WidgetBuilder widgetBuilder = new WidgetBuilder(new Class[]{BoldWidget.class});
	String text = "'''bold text'''";
	ParentWidget parent = new BoldWidget(new MockWidgetRoot(), "'''bold text'''");
	AtomicBoolean failFlag = new AtomicBoolean();
	failFlag.set(false);

	//This is our best attempt to get a race condition
	//by creating large number of threads.
	for (int i = 0; i < 25000; i++) {
		WidgetBuilderThread widgetBuilderThread = new WidgetBuilderThread(widgetBuilder, text, parent, failFlag);
		Thread thread = new Thread(widgetBuilderThread);
		thread.start(); 
	}
	assertEquals(false, failFlag.get()); 
}


public void testCompareTo() throws Exception {
	WikiPagePath a = PathParser.parse("PageA");
	WikiPagePath ab = PathParser.parse("PageA.PageB");
	WikiPagePath b = PathParser.parse("PageB");
	WikiPagePath aa = PathParser.parse("PageA.PageA");
	WikiPagePath bb = PathParser.parse("PageB.PageB");
	WikiPagePath ba = PathParser.parse("PageB.PageA");

	assertTrue(a.compareTo(a) == 0); // a == a
	assertTrue(a.compareTo(b) != 0); // a != b
	assertTrue(ab.compareTo(ab) == 0); // ab == ab
	assertTrue(a.compareTo(b) == -1); // a < b
	assertTrue(aa.compareTo(ab) == -1); // aa < ab
	assertTrue(ba.compareTo(bb) == -1); // ba < bb
	assertTrue(b.compareTo(a) == 1); // b > a
	assertTrue(ab.compareTo(aa) == 1); // ab > aa
	assertTrue(bb.compareTo(ba) == 1); // bb > ba
}


// Don't run unless you
// have some time to kill.
public void _testWithReallyBigFile() {
	writeLinesToFile(10000000);
	response.setBody(testFile);
	response.readyToSend(this);
	String responseString = output.toString();
	assertSubString("Content-Length: 1000000000", responseString);
	assertTrue(bytesSent > 1000000000);
}


//TODO-MdM these are not needed
// We expect this to go away when we do the checkout model
protected VersionInfo makeVersion() throws Exception {
	return null;
}


String listItemContent = match.group(3).trim();
// the trim is real important. It removes the starting
// spaces that could cause the item to be recognized
// as another list.
new ListItemWidget(this, listItemContent, this.level + 1);
return buildList(text.substring(match.end()));


public void loadProperties() {
	try {
		String propertiesPath = propertiesLocation + "/" + PROPERTIES_FILE;
		FileInputStream propertiesStream = new FileInputStream(propertiesPath);
		loadedProperties.load(propertiesStream);
	} catch(IOException e) {
	// No properties files means all defaults are loaded
	}
}


public abstract class ContainerBase implements Container, Lifecycle, Pipeline, MBeanRegistration, Serializable {
	/**
	* The processor delay for this component.
	*/
	protected int backgroundProcessorDelay = -1;

	/**
	* The lifecycle event support for this component.
	*/
	protected LifecycleSupport lifecycle = new LifecycleSupport(this);
	
	/**
	* The container event listeners for this Container.
	*/
	protected ArrayList listeners = new ArrayList();

	// A lot of similar codes
}




// Utility method that returns when this.closed is true. Throws an exception
// if the timeout is reached.
public synchronized void waitForClose(final long timeoutMillis) throws Exception {
	if(!closed) {
		wait(timeoutMillis);
		if(!closed)
			throw new Exception("MockResponseSender could not be closed");
	}
}


/**
* Returns the day of the month.
*
* @return the day of the month.
*/
public int getDayOfMonth() {
	return dayOfMonth;
}


/** The name. */
private String name;

/** The version. */
private String version;

/** The licenceName. */
private String licenceName;

/** The version. */
private String info;


/**
* Port on which fitnesse would run. Defaults to <b>8082</b>.
*
* @param fitnessePort
*/

public void setFitnessePort(int fitnessePort) {
	this.fitnessePort = fitnessePort;
}

/*
* start with an array that is big enough to hold all the pixels
* (plus filter bytes), and an extra 200 bytes for header info
*/
this.pngBytes = new byte[((this.width + 1) * this.height * 3) + 200];


package fitnesse.wikitext.widgets;

import java.util.regex.*;

public class BoldWidget extends ParentWidget {
	public static final String REGEXP = "'''.+?'''";
	private static final Pattern pattern = Pattern.compile("'''(.+?)'''", Pattern.MULTILINE + Pattern.DOTALL);

	public BoldWidget(ParentWidget parent, String text) throws Exception {
		super(parent);
		Matcher match = pattern.matcher(text);
		match.find();
		addChildWidgets(match.group(1));
	}

	public String render() throws Exception {
		StringBuffer html = new StringBuffer("<b>");
		html.append(childHtml()).append("</b>");
		return html.toString();
	} 
}

public class ReporterConfig {
	private String m_className;
	private List<Property> m_properties = new ArrayList<Property>();

	public void addProperty(Property property) { 
		m_properties.add(property);
	}
}

public class TestSuite implements Test {
	static public Test createTest(Class<? extends TestCase> theClass, String name) {...}

	public static Constructor<? extends TestCase> getTestConstructor(Class<? extends TestCase> theClass) throws NoSuchMethodException {...}

	public static Test warning(final String message) {...}

	private static String exceptionToString(Throwable t) {...}

	private String fName;

	private Vector<Test> fTests= new Vector<Test>(10);

	public TestSuite() { }

	public TestSuite(final Class<? extends TestCase> theClass) {...}

	public TestSuite(Class<? extends TestCase> theClass, String name) { ..}
	// and so on
}

public class WikiPageResponder implements SecureResponder {
	protected WikiPage page;
	protected PageData pageData;
	protected String pageTitle;
	protected Request request;
	protected PageCrawler crawler;

	public Response makeResponse(FitNesseContext context, Request request) throws Exception {
		String pageName = getPageNameOrDefault(request, "FrontPage");
		loadPage(pageName, context);
		if (page == null)
			return notFoundResponse(context, request);
		else
			return makePageResponse(context);
	}

	private String getPageNameOrDefault(Request request, String defaultPageName) {
		String pageName = request.getResource();
		if (StringUtil.isBlank(pageName))
			pageName = defaultPageName;
		return pageName;
	}

	protected void loadPage(String resource, FitNesseContext context) throws Exception {
		WikiPagePath path = PathParser.parse(resource);
		crawler = context.root.getPageCrawler();
		crawler.setDeadEndStrategy(new VirtualEnabledPageCrawler());
		page = crawler.getPage(context.root, path);
		if (page != null)
			pageData = page.getData();
	}

	private Response notFoundResponse(FitNesseContext context, Request request) throws Exception {
		return new NotFoundResponder().makeResponse(context, request);
	}

	private SimpleResponse makePageResponse(FitNesseContext context) throws Exception {
		....
	}
  

public class Quadratic {
	public static double root1(double a, double b, double c) {
		double determinant = determinant(a, b, c);
		return (-b + Math.sqrt(determinant)) / (2*a);
	}

	public static double root2(int a, int b, int c) {
		double determinant = determinant(a, b, c);
		return (-b - Math.sqrt(determinant)) / (2*a);
	}

	private static double determinant(double a, double b, double c) {
		return b*b - 4*a*c;
	}
}

private void measureLine(String line) {
	lineCount++;
	int lineSize = line.length();
	totalChars += lineSize;
	lineWidthHistogram.addLine(lineSize, lineCount);
	recordWidestLine(lineSize);
}


public class FitNesseExpediter implements ResponseSender {\
	private 	Socket 		socket;

private private private private private private protected private private private
Socket InputStream OutputStream Request Response FitNesseContext long
long long boolean
socket;
input;
output;
request;
response;
context; requestParsingTimeLimit; requestProgress; requestParsingDeadline; hasError;
public FitNesseExpediter(Socket s,
FitNesseContext context) throws Exception
{
}
this.context =
socket =
input =
output = requestParsingTimeLimit =



public class FitNesseServer implements SocketServer {
	private FitNesseContext context;

	public FitNesseServer(FitNesseContext context) {
		this.context = context;
	}

	public void serve(Socket s) {
		serve(s, 10000);
	}

	public void serve(Socket s, long requestTimeout) {
		try {
			FitNesseExpediter sender = new FitNesseExpediter(s, context);
			sender.setRequestParsingTimeLimit(requestTimeout);
			sender.start();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
}

public class CommentWidget extends TextWidget {
	public static final String REGEXP = "^#[^\r\n]*(?:(?:\r\n)|\n|\r)?";
	public CommentWidget(ParentWidget parent, String text){super(parent, text);}
	public String render() throws Exception {return ""; }
}

public class CommentWidget extends TextWidget {
	public static final String REGEXP = "^#[^\r\n]*(?:(?:\r\n)|\n|\r)?";

	public CommentWidget(ParentWidget parent, String text){
		super(parent, text);
	}

	public String render() throws Exception {
		return "";
	}
}


public class Point {
	public double x;
	public double y;
}

public interface Point {
	double getX();
	double getY();
	void setCartesian(double x, double y);
	double getR();
	double getTheta();
	void setPolar(double r, double theta);
}



public interface Vehicle {
	double getFuelTankCapacityInGallons();
	double getGallonsOfGasoline();
}


public interface Vehicle {
	double getPercentFuelRemaining();
}


public class Square {
	public Point topLeft;
	public double side;
}

public class Rectangle {
	public Point topLeft;
	public double height;
	public double width;
}

public class Circle {
	public Point center;
	public double radius;
}

public class Geometry {
	public final double PI = 3.141592653589793;
	public double area(Object shape) throws NoSuchShapeException {
		if (shape instanceof Square) {
			Square s = (Square)shape;
			return s.side * s.side;
		} else if (shape instanceof Rectangle) {
			Rectangle r = (Rectangle)shape;
			return r.height * r.width;
		} else if (shape instanceof Circle) {
			Circle c = (Circle)shape;
			return PI * c.radius * c.radius;
		}
		throw new NoSuchShapeException();
	}
}
  

public class Square implements Shape {
	private Point topLeft;
	private double side;
	public double area() {
		return side*side;
	}
}

public class Rectangle implements Shape {
	private Point topLeft;
	private double height;
	private double width;
	public double area() {
		return height * width;
	}
}

public class Circle implements Shape {
	private Point center;
	private double radius;
	public final double PI = 3.141592653589793;
	public double area() {
		return PI * radius * radius;
	}
}

final String outputDir = ctxt.options.scratchDir.absolutePath;


Options opts = ctxt.getOptions();
File scratchDir = opts.getScratchDir();
final String outputDir = scratchDir.getAbsolutePath();


public class DeviceController { 
	...
	public void sendShutDown() {
	DeviceHandle handle = getHandle(DEV1);

	// Check the state of the device
	if (handle != DeviceHandle.INVALID) {
	// Save the device status to the record field
		retrieveDeviceRecord(handle);

	// If not suspended, shut down
		if (record.getStatus() != DEVICE_SUSPENDED) {
			pauseDevice(handle);
			clearDeviceWorkQueue(handle);
			closeDevice(handle);
		} else {
			logger.log("Device suspended. Unable to shut down");
		}
	} else {
		logger.log("Invalid handle for: " + DEV1.toString()); }
	}
	... 
}

public class DeviceController {
	...
	public void sendShutDown() {
		try {
			tryToShutDown();
		} catch (DeviceShutDownError e) {
			logger.log(e);
		}
	}

	private void tryToShutDown() throws DeviceShutDownError {
		DeviceHandle handle = getHandle(DEV1);
		DeviceRecord record = retrieveDeviceRecord(handle);
		pauseDevice(handle);
		clearDeviceWorkQueue(handle);
		closeDevice(handle);
	}

	private DeviceHandle getHandle(DeviceID id) {
		...
		throw new DeviceShutDownError("Invalid handle for: " + id.toString());
		...
	}
	...
}

try {
	MealExpenses expenses = expenseReportDAO.getMeals(employee.getID());
	m_total += expenses.getTotal();
} catch(MealExpensesNotFound e) {
	m_total += getMealPerDiem();
}


MealExpenses expenses = expenseReportDAO.getMeals(employee.getID());
m_total += expenses.getTotal();

public class PerDiemMealExpenses implements MealExpenses {
	public int getTotal() {
	// return the per diem default
	}
}


public void registerItem(Item item) {
	if (item != null) {
		ItemRegistry registry = peristentStore.getItemRegistry();
		if (registry != null) {
			Item existing = registry.getItem(item.getID());
			if (existing.getBillingPeriod().hasRetailOwner()) {
				existing.register(item);
			}
		}
	}
}

public void test() {

	List<Employee> employees = getEmployees();
	for(Employee e : employees) {
		totalPay += e.getPay();
	}

}

public List<Employee> getEmployees() { 
	if( .. there are no employees .. )
		return Collections.emptyList();
}


• clear() void – Map
• containsKey(Object key) boolean – Map
• containsValue(Object value) boolean – Map • entrySet() Set – Map
• equals(Object o) boolean – Map
• get(Object key) Object – Map
• getClass() Class<? extends Object> – Object • hashCode() int – Map
• isEmpty() boolean – Map
• keySet() Set – Map
• notify() void – Object
• notifyAll() void – Object
• put(Object key, Object value) Object – Map • putAll(Map t) void – Map
• remove(Object key) Object – Map
• size() int – Map
• toString() String – Object
• values() Collection – Map
• wait() void – Object
• wait(long timeout) void – Object
• wait(long timeout, int nanos) void – Object


Map<Sensor> sensors = new HashMap<Sensor>();
...
Sensor s = sensors.get(sensorId );



public class Sensors {
	private Map sensors = new HashMap();
	public Sensor getById(String id) {
		return (Sensor) sensors.get(id);
	}
}


@Test
public void testLogCreate() {
	Logger logger = Logger.getLogger("MyLogger");
	logger.info("hello");
}


@Test
public void testLogAddAppender() {
	Logger logger = Logger.getLogger("MyLogger");
	ConsoleAppender appender = new ConsoleAppender();
	logger.addAppender(appender);
	logger.info("hello");
}



@Test
public void testLogAddAppender() {
	Logger logger = Logger.getLogger("MyLogger");
	logger.removeAllAppenders();
	logger.addAppender(new ConsoleAppender(
		new PatternLayout("%p %t %m%n"),
		ConsoleAppender.SYSTEM_OUT)
	);
	logger.info("hello");
}



public class LogTest {
	private Logger logger;

	@Before
	public void initialize() {
		logger = Logger.getLogger("logger");
		logger.removeAllAppenders();
		Logger.getRootLogger().removeAllAppenders();
	}

	@Test
	public void basicLogger() {
		BasicConfigurator.configure();
		logger.info("basicLogger");
	}

	@Test
	public void addAppenderWithStream() {
		logger.addAppender(new ConsoleAppender( new PatternLayout("%p %t %m%n"), ConsoleAppender.SYSTEM_OUT));
		logger.info("addAppenderWithStream");
	}

	@Test
	public void addAppenderWithoutStream() {
		logger.addAppender(new ConsoleAppender( new PatternLayout("%p %t %m%n")));
		logger.info("addAppenderWithoutStream");
	}
}

/**
* Miscellaneous tests for the addMonths() method.
*/
public void testAddMonths() {
	SerialDate d1 = SerialDate.createInstance(31, 5, 2004);

	SerialDate d2 = SerialDate.addMonths(1, d1);
	assertEquals(30, d2.getDayOfMonth());
	assertEquals(6, d2.getMonth());
	assertEquals(2004, d2.getYYYY());

	SerialDate d3 = SerialDate.addMonths(2, d1);
	assertEquals(31, d3.getDayOfMonth());
	assertEquals(7, d3.getMonth());
	assertEquals(2004, d3.getYYYY());

	SerialDate d4 = SerialDate.addMonths(1, SerialDate.addMonths(1, d1));
	assertEquals(30, d4.getDayOfMonth());
	assertEquals(7, d4.getMonth());
	assertEquals(2004, d4.getYYYY());
}

public class Sql {
	public Sql(String table, Column[] columns)
	public String create()
	public String insert(Object[] fields)
	public String selectAll()
	public String findByKey(String keyColumn, String keyValue)
	public String select(Column column, String pattern)
	public String select(Criteria criteria)
	public String preparedInsert()
	private String columnList(Column[] columns)
	private String valuesList(Object[] fields, final Column[] columns)
	private String selectWithCriteria(String criteria)
	private String placeholderList(Column[] columns)
}



abstract public class Sql {
	public Sql(String table, Column[] columns)
	abstract public String generate();
}

public class CreateSql extends Sql {
	public CreateSql(String table, Column[] columns)
	@Override public String generate()
}

public class SelectSql extends Sql {
	public SelectSql(String table, Column[] columns)
	@Override public String generate()
}

public class InsertSql extends Sql {
	public InsertSql(String table, Column[] columns, Object[] fields)
	@Override public String generate()
	private String valuesList(Object[] fields, final Column[] columns)
}

public class SelectWithCriteriaSql extends Sql {
	public SelectWithCriteriaSql(String table, Column[] columns, Criteria criteria)
	@Override public String generate()
}

...

public class Where {
	public Where(String criteria)
	public String generate()
}

public class ColumnList {
	public ColumnList(Column[] columns)
	public String generate()
}

